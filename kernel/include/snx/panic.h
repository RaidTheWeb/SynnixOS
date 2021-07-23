#pragma once
#ifndef SNX_PANIC_H
#define SNX_PANIC_H

#include <basic.h>
#include <assert.h>
#include <snx/debug.h>
#include <stdio.h>


#include <snx/cpu.h>
#include <x86/interrupt.h>

/** @file
 * @brief Helper functions for kernel panics
 * 
 */

noinline void break_point();

#define panic(...)                                                             \
    do {                                                                       \
        break_point();                                                         \
        disable_irqs();                                                        \
        printf("[PANIC] " __VA_ARGS__);                                        \
        halt();                                                                \
        __builtin_unreachable();                                               \
    } while (0)

#define panic_bt(...)                                                          \
    do {                                                                       \
        break_point();                                                         \
        disable_irqs();                                                        \
        printf("[PANIC] " __VA_ARGS__);                                        \
        asm volatile("int $0x82");                                             \
        halt();                                                                \
    } while (0)

#define panic_gbt(...)                                                         \
    do {                                                                       \
        break_point();                                                         \
        disable_irqs();                                                        \
        printf("[PANIC] " __VA_ARGS__);                                        \
        backtrace_all();                                                       \
        asm volatile("int $0x82");                                             \
        halt();                                                                \
    } while (0)

#endif
