#ifndef ORIGINALIS_CORE_CONTEXT_H
#define ORIGINALIS_CORE_CONTEXT_H

/**
 * @author Ronald Tavarez
 * @date 2023-10-17
 *
 * Originalis - Core Compiler and Platform Context Header
 * -----------------------------------------
 * This header aims to detect and define macros based on the active compiler, 
 * operating system, and CPU architecture. It provides a unified method of checking 
 * platform/compiler specifics throughout the codebase, Facilitating platform-
 * agnostic development, and allowing easy checks for platform/compiler specifics.
 * 
 */

/* COMPILER CLANG */
#if defined(__clang__)
    #define COMPILER_CLANG 1

    /* DETECT OPERATING SYSTEM */
    #if defined(__ANDROID__)
        #define OS_ANDROID 1
    #elif defined(_WIN32)
        #define OS_WINDOWS 1
    #elif defined(__gnu_linux__)
        #define OS_LINUX 1
    #elif defined(__APPLE__) && defined(__MACH__)
        #if TARGET_OS_IPHONE || TARGET_OS_IOS
            #define OS_IOS 1
        #else
            #define OS_MAC 1
        #endif
    #else
        #error "Missing Operating System Detection"
    #endif

    /* DETECT CPU ARCHITECTURE */
    #if defined(__amd64__) || defined(__x86_64__)
        #define ARCH_X64 1
    #elif defined(__i386__)
        #define ARCH_X86 1
    #elif defined(__arm__)
        #define ARCH_ARM 1
    #elif defined(__aarch64__)
        #define ARCH_ARM64 1
    #else
        #error "Missing CPU Architecture Detection"
    #endif

/* COMPILER MSVC */
#elif defined(_MSC_VER)
    #define COMPILER_CL 1

    /* DETECT OPERATING SYSTEM */
    #if defined(_WIN32)
        #define OS_WINDOWS 1
    #else
        #error "Missing Operating System Detection"
    #endif

    /* DETECT CPU ARCHITECTURE */
    #if defined(_M_AMD64) || defined(_M_X64)
        #define ARCH_X64 1
    #elif defined(_M_IX86)
        #define ARCH_X86 1
    #elif defined(_M_ARM)
        #define ARCH_ARM 1
    #elif defined(_M_ARM64)
        #define ARCH_ARM64 1
    #else
        #error "Missing CPU Architecture Detection"
    #endif

/* COMPILER GCC */
#elif defined(__GNUC__)
    #define COMPILER_GCC 1

    /* DETECT OPERATING SYSTEM */
    #if defined(_WIN32) || defined(_WIN64)
        #define OS_WINDOWS 1
    #elif defined(__linux__)
        #define OS_LINUX 1
    #elif defined(__APPLE__) && defined(__MACH__)
        #if TARGET_OS_IPHONE || TARGET_OS_IOS
            #define OS_IOS 1
        #else
            #define OS_MAC 1
        #endif
    #else
        #error "Missing Operating System Detection"
    #endif  

    /* DETECT CPU COMPILER */
    #if defined(__amd64__) || defined(__x86_64__)
        #define ARCH_X64 1
    #elif defined(__i386__)
        #define ARCH_X86 1
    #elif defined(__arm__)
        #define ARCH_ARM 1
    #elif defined(__aarch64__)
        #define ARCH_ARM64 1
    #else
        #error "Missing CPU Architecture Detection"
    #endif

#else
    #error "Missing Compiler Detection"
#endif


// Zero fill missing context macros
#if !defined(COMPILER_CL)
    #define COMPILER_CL 0
#endif

#if !defined(COMPILER_CLANG)
    #define COMPILER_CLANG 0
#endif

#if !defined(COMPILER_GCC)
    #define COMPILER_GCC 0
#endif

#if !defined(OS_WINDOWS)
    #define OS_WINDOWS 0
#endif

#if !defined(OS_LINUX)
    #define OS_LINUX 0
#endif

#if !defined(OS_ANDROID)
    #define OS_ANDROID 0
#endif

#if !defined(OS_IOS)
    #define OS_IOS 0
#endif

#if !defined(OS_MAC)
    #define OS_MAC 0
#endif

#if !defined(ARCH_X64)
    #define ARCH_X64 0
#endif

#if !defined(ARCH_X86)
    #define ARCH_X86 0
#endif

#if !defined(ARCH_ARM)
    #define ARCH_ARM 0
#endif 

#if !defined(ARCH_ARM64)
    #define ARCH_ARM64 0
#endif

#endif  // CORE_CONTEXT_H
