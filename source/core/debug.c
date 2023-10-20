#include "core/debug.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


static MemoryAllocation * head_allocation = NULL;
static const uint8_t DEBUG_MEMORY_GUARD_VALUE[DEBUG_MEMORY_GUARD_SIZE] = {
    0x00, 0x00, 0x00, 0x00, 
    0xCC, 0xCC, 0xCC, 0xCC, 
    0xCC, 0xCC, 0xCC, 0xCC, 
    0x00, 0x00, 0x00, 0x00
};

/**
 * @brief Helper function to check the memory guard bytes for a buffer overrun.
 * 
 * @param address The address of the allocated memory block.
 * @param size The size of the allocated memory block.
 * @return true if the memory guard bytes are intact, 
 * @return false if they have been overwritten.
 */
bool is_memory_guard_intact(void * address, size_t size) {
    uint8_t * guard_bytes = (uint8_t *)address + size;
    return memcmp(guard_bytes, DEBUG_MEMORY_GUARD_VALUE, DEBUG_MEMORY_GUARD_SIZE) == 0;
}

/**
 * @brief Set the memory guard bytes to a known value to detect buffer overruns.
 * 
 * @param address The address of the allocated memory block.
 * @param size The size of the allocated memory block.
 * @details This function assumes that the memory guard bytes are intact and address points to a valid memory block.
 */
static inline void set_memory_guard_bytes(void * address, size_t size) {
    uint8_t * guard_bytes = (uint8_t *)address + size;
    memcpy(guard_bytes, DEBUG_MEMORY_GUARD_VALUE, DEBUG_MEMORY_GUARD_SIZE);
}

/**
 * @brief Helper function to allocate memory and set the memory guard bytes to a known value to detect buffer overruns.
 * 
 * @param size The size of the memory to allocate.
 * @return void* A pointer to the allocated memory block, or NULL on failure.
 */
static void * allocate_memory_with_guard(size_t size) {
    void * address = malloc(size + DEBUG_MEMORY_GUARD_SIZE);
    if (address)
        set_memory_guard_bytes(address, size); 
    return address;
}

/**
 * @brief Helper function to allocate and initialize a MemoryAllocation structure.
 * 
 * @param address The address of the allocated memory block.
 * @param size The size of the allocated memory block.
 * @param file The name of the source file where the memory allocation occurred.
 * @param line The line number in the source file where the memory allocation occurred.
 * @return MemoryAllocation * A pointer to the initialized MemoryAllocation structure, or NULL on failure.
 */
static MemoryAllocation * create_memory_allocation(void * address, size_t size, const char * file, int line) {
    // Allocate memory for the structure
    MemoryAllocation * allocation = (MemoryAllocation *)malloc(sizeof(MemoryAllocation));
    if (allocation) {
        // Initialize the structure fields
        allocation->address = address;
        allocation->size = size;
        allocation->file = file;
        allocation->line = line;
        // Insert the new allocation record at the beginning of the linked list
        allocation->next = head_allocation;
    }
    return allocation;
}

/**
 * @brief Helper function to find a MemoryAllocation structure for the given address.
 *  
 * @param address The address of the allocated memory block.
 * @return MemoryAllocation * A pointer to the MemoryAllocation structure for the given address, or NULL if not found.
 */
static MemoryAllocation * find_allocation(void * address) {
    MemoryAllocation * allocation = head_allocation;
    while (allocation) {
        if (allocation->address == address) {
            return allocation;
        }
        allocation = allocation->next;
    }
    return NULL;
}

/**
 * @brief Helper function to update the information for a MemoryAllocation structure.
 * 
 * @param address The address of the allocated memory block.
 * @param size The size of the allocated memory block.
 * @param file The name of the source file where the memory allocation occurred.
 * @param line The line number in the source file where the memory allocation occurred.
 */
static void update_memory_allocation(void * address, size_t size, const char * file, int line) {
    MemoryAllocation * allocation = find_allocation(address);
    if (allocation) {
        allocation->size = size;
        allocation->file = file;
        allocation->line = line;
    }
}

/**
 * 
 * @brief Helper function to remove a MemoryAllocation structure from the global linked list.
 * 
 * @param target The MemoryAllocation structure to remove.
 * @details This function assumes that the allocation is in the list.
 */
static void remove_allocation_from_list(MemoryAllocation * target) {
    // If the allocation is the head of the list, update the head pointer.
    if (head_allocation == target) {
        head_allocation = target->next;
        return;
    }

    // Else, find the previous allocation in the list.
    MemoryAllocation * previous = head_allocation;
    while (previous && previous->next != target)
        previous = previous->next;

    // If we found the previous allocation, remove the current allocation from the list.
    if (previous)
        previous->next = target->next;  
    
}

void * debug_malloc(size_t size, const char * file, int line) {
    // Allocate the requested memory, including space for the guard bytes, and return NULL if the allocation failed.
    void * address = allocate_memory_with_guard(size);
    if (!address) {
        LOG_CONSOLE_ERROR("Failed to allocate memory with guard.");
        return NULL;
    }

    // Initialize the memory to DEBUG_MEMORY_INIT_VALUE to detect uninitialized memory reads.
    memset(address, DEBUG_MEMORY_INIT_VALUE, size);
    
    // Create a new allocation record and add it to the list, or return NULL if the allocation failed.
    MemoryAllocation * allocation = create_memory_allocation(address, size, file, line);
    if (!allocation) {
        LOG_CONSOLE_ERROR("Failed to create memory allocation.");
        free(address);
        return NULL;
    }

    // Update the head pointer to the new allocation record.
    head_allocation = allocation;

    // Return the address of the allocated memory block.
    return address;
}


void * debug_realloc(void * address, size_t size, const char * file, int line) {
    // If the address is NULL, just allocate the requested memory.
    if (!address) 
        return debug_malloc(size, file, line);

    // Check for buffer overruns before reallocating.
    MemoryAllocation * target = find_allocation(address);
    if (target && !is_memory_guard_intact(address, target->size)) {
        LOG_CONSOLE_ERROR("Buffer overrun detected before realloc.");
        return NULL;
    }

    // Reallocate the requested memory, including space for the guard bytes, and return NULL if the allocation failed.
    void * new_address = allocate_memory_with_guard(size);
    if (!new_address) {
        LOG_CONSOLE_ERROR("Failed to allocate memory with guard.");
        return NULL;
    }

    // Copy the contents of the old memory block to the new memory block.
    if (target) {
        memcpy(new_address, address, (size > target->size) ? target->size : size);
        debug_free(address);
        update_memory_allocation(new_address, size, file, line);
        return new_address;
    }
    
    // If allocation is not in the list, clean up memory and return NULL.
    LOG_CONSOLE_ERROR("Target memory address not found in allocation list during realloc.");
    free(new_address);
    return NULL;
}


void * debug_calloc(size_t count, size_t size, const char * file, int line) {
    // Allocate the requested memory, including space for the guard bytes, and return NULL if the allocation failed.
    void * address = debug_malloc(count * size, file, line);
    if (!address) {
        LOG_CONSOLE_ERROR("Failed to allocate memory with guard.");
        return NULL;
    }

    // Zero-initialize the memory since its meant to be calloc. debug_malloc already initialized it to DEBUG_MEMORY_INIT_VALUE.
    memset(address, 0, count * size);

    // Return the address of the allocated memory block.
    return address;
}


void debug_free(void * address) {
    if (!address) return;  

    // Find the target allocation in the list.
    MemoryAllocation * target = find_allocation(address);
    if (!target) {
        LOG_CONSOLE_ERROR("Target memory address not found in allocation list during free.");
        return;
    }

    // Check for buffer overruns before freeing.
    if (!is_memory_guard_intact(address, target->size))
        LOG_CONSOLE_ERROR("Buffer overrun detected before free.");
    

    // Remove the allocation from the list and free it.
    remove_allocation_from_list(target);
    free(target);
    free(address);
}


void report_memory_leaks(void) {
    MemoryAllocation * allocation = head_allocation;
    while (allocation) {
        char error_buffer[1024];
        snprintf(error_buffer, sizeof(error_buffer), 
            "Memory leak detected at %s:%d. %d bytes were allocated at %p.", 
            allocation->file, allocation->line, allocation->size, allocation->address);
        LOG_CONSOLE_ERROR(error_buffer);
        allocation = allocation->next;
    }
}