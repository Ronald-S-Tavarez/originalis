#ifndef ORIGINALIS_CORE_DEBUG_H 
#define ORIGINALIS_CORE_DEBUG_H

#include "core/log.h"
#include "core/color.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @author Ronald Tavarez
 * @file debug.h
 * @date 2023-10-19
 * @brief Debugging utilities for the Originalis codebase.
 * 
 * This header provides debugging helper macros to evaluate and print expressions.
 */

#define DEBUG_MEMORY_GUARD_SIZE 16
#define DEBUG_MEMORY_INIT_VALUE 0xCC

/**
 * @brief Helper function to check the memory guard bytes for a buffer overrun.
 * 
 * @param address The address of the allocated memory block.
 * @param size The size of the allocated memory block.
 * @return true if the memory guard bytes are intact,
 * @return false if they have been overwritten.
 */
bool is_memory_guard_intact(void * address, size_t size);

/**
 * @brief Structure to track memory allocations. 
 */
typedef struct MemoryAllocation {
    void * address;                 /** Address of the allocated memory. */
    int size;                       /** Size of the allocated memory. */
    const char * file;              /** File where the memory was allocated. */
    int line;                       /** Line number where the memory was allocated. */
    struct MemoryAllocation * next; /** Pointer to the next memory allocation. */
} MemoryAllocation;

/**
 * Debug version of malloc. Allocates memory and tracks it for memory leaks.
 * @param size The size of the memory to allocate.
 * @param file The name of the source file where the memory allocation is being requested.
 * @param line The line number in the source file where the memory allocation is being requested.
 * @return A pointer to the allocated memory block, or NULL on failure.
 */
void * debug_malloc(size_t size, const char * file, int line);

/**
 * Debug version of realloc. Reallocates memory and updates its tracking information.
 * @param address The current address of the memory block.
 * @param size The new size of the memory block.
 * @param file The name of the source file where the memory reallocation is being requested.
 * @param line The line number in the source file where the memory reallocation is being requested.
 * @return A pointer to the reallocated memory block, or NULL on failure.
 */
void * debug_realloc(void * address, size_t size, const char * file, int line);

/**
 * Debug version of calloc. Allocates zero-initialized memory and tracks it for memory leaks.
 * @param count Number of elements to allocate.
 * @param size The size of each element.
 * @param file The name of the source file where the memory allocation is being requested.
 * @param line The line number in the source file where the memory allocation is being requested.
 * @return A pointer to the allocated memory block, or NULL on failure.
 */
void * debug_calloc(size_t count, size_t size, const char * file, int line);


/**
 * Debug version of free. Frees allocated memory and removes its tracking information.
 * @param address The address of the memory block to free.
 */
void debug_free(void * address);

/**
 * Reports any memory blocks that were allocated but not freed.
 */
void report_memory_leaks(void);

/**
 * @brief Prints a message to the console with the given log level using the given format and arguments.
 * 
 * @param func The name of the function where the message is being printed.
 * @param file The name of the source file where the message is being printed.
 * @param line The line number in the source file where the message is being printed. 
 * @param format The format string for the message.
 * @param ...  The arguments for the format string.
 */
static void log_assert_message(const char * func, const char * file, int line, const char * format, ...) {
    char buffer[1024];
    va_list arguments;
    va_start(arguments, format);
    vsnprintf(buffer, sizeof(buffer), format, arguments);
    va_end(arguments);
    log_message_to_console(LOG_LEVEL_ERROR, func, file, line, buffer);
}

#define STATEMENT(statement) do { statement; } while (0) 

#if !defined(ASSERT_BREAK)
    #define ASSERT_BREAK() (*(int*)0 = 0)
#endif

#define STATIC_ASSERT(condition, message) typedef char static_assertion_##message[(condition) ? 1 : -1]

#define ASSERT(condition, message) STATEMENT( \
    if (!(condition)) { \
        LOG_CONSOLE_ERROR(message); \
        ASSERT_BREAK(); \
    } \
)

#define ASSERT_FORMAT(condition, format, ...) STATEMENT( \
    if (!(condition)) { \
        log_assert_message(__FUNCTION__, \
            __FILE__, \
            __LINE__, \
            "Assertion Failed: " #condition ". " format, \
            ##__VA_ARGS__); \
        ASSERT_BREAK(); \
    } \
)


#endif // CORE_DEBUG_H