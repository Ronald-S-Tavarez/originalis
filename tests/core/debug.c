#include "core/debug.h"
#include "core/log.h"
#include <stdint.h>
#include <stdbool.h>

void test_debug_malloc(void);
//void test_debug_calloc(void);
//void test_debug_realloc(void);
//void test_debug_free(void);
//void test_report_memory_leaks(void);
//void test_assert_macros(void);
 

int main(void) {
    test_debug_malloc();
    LOG_CONSOLE_SUCCESS("test_debug_malloc passed.");
    //test_debug_calloc();
    //test_debug_realloc();
    //test_debug_free();
    //test_report_memory_leaks();
    //test_assert_macros();
    return 0;
}

void test_debug_malloc(void) {
    LOG_CONSOLE_INFO("Testing debug_malloc...");

    // Basic Allocation Test.
    int * int_ptr = (int *)debug_malloc(sizeof(int), __FILE__, __LINE__);
    ASSERT(int_ptr != NULL, "debug_malloc returned NULL.");
    printf("malloc returned: %x | expected %x\n", int_ptr, DEBUG_MEMORY_INIT_VALUE);
    ASSERT(*int_ptr == DEBUG_MEMORY_INIT_VALUE, "debug_malloc did not initialize memory to DEBUG_MEMORY_INIT_VALUE.");
    LOG_CONSOLE_SUCCESS("debug_malloc passed basic allocation test.");

    // Reassignment Test.
    *int_ptr = 10;
    ASSERT(*int_ptr == 10, "debug_malloc did not return a valid pointer to the allocated memory.");
    LOG_CONSOLE_SUCCESS("debug_malloc passed reassignment test.");

    // Memory Guard Overrun Test.
    uint8_t * byte_ptr = (uint8_t *)(int_ptr + 1);
    *byte_ptr = 0xEE; // Simulating an overrun.
    ASSERT(!is_memory_guard_intact(int_ptr, sizeof(int)), "Memory guard check did not detect an overrun when it should have.");
    LOG_CONSOLE_SUCCESS("debug_malloc passed memory guard overrun test.");

    debug_free(int_ptr);
}