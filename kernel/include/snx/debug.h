#pragma once
#ifndef SNX_DEBUG_H
#define SNX_DEBUG_H

#include <basic.h>
#include <stdio.h>

/** @file
 * @brief Various debugging tools 
 * 
 */

#ifdef DEBUG

#define do_debug true
#define DEBUG_PRINTF(...)                                                      \
    do { printf("[DEBUG] " __VA_ARGS__); } while (0)

#else // DEBUG == false

#define do_debug false
#define DEBUG_PRINTF(...)

#endif // DEBUG == true

#define WARN_PRINTF(...)                                                       \
    do { printf("[WARN!] " __VA_ARGS__); } while (0)

#define UNREACHABLE() assert("not reachable" && 0)

#define gassert(assertion)                                                     \
    do {                                                                       \
        if (!(assertion)) {                                                    \
            printf("[ASSERT] '" #assertion "' @ " __FILE__                     \
                   ":" QUOTE(__LINE__) "\n");                                  \
            panic_gbt();                                                       \
            __builtin_unreachable();                                           \
        }                                                                      \
    } while (0)

/**
 * @brief Backtrace from pointer
 * 
 * @param bp 
 * @param ip 
 * @param callback 
 */
void backtrace(uintptr_t bp, uintptr_t ip,
               void (*callback)(uintptr_t bp, uintptr_t ip));
/**
 * @brief Back trace from point
 * 
 */
void backtrace_from_here(void);
/**
 * @brief Back trace from point but using `ip`
 * 
 * @param bp 
 * @param ip 
 */
void backtrace_from_with_ip(uintptr_t bp, uintptr_t ip);
void print_perf_trace(uintptr_t bp, uintptr_t ip);

/**
 * @brief Perform a memory dump
 * 
 * @param ptr 
 * @param len 
 * @return int 
 */
int dump_mem(void *ptr, size_t len);
/**
 * @brief Perform a hex dump
 * 
 * @param len 
 * @param ptr 
 * @return int 
 */
int hexdump(size_t len, char ptr[len]);

__NOINLINE void break_point();

#endif
