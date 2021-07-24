#pragma once
#ifndef SNX_X86_INTERRUPT_H
#define SNX_X86_INTERRUPT_H

#include <basic.h>
#include "cpu.h"

/** @file
 * @brief x86 Interrupt Headers
 * 
 */

void install_isrs(void);

/**
 * @brief Enable IRQs
 * 
 */
void enable_irqs(void);

/**
 * @brief Disable IRQs
 * 
 */
void disable_irqs(void);
void assert_irqs_enabled(void);
void assert_irqs_disabled(void);
void c_interrupt_shim(interrupt_frame *r);

/**
 * @brief Make the jump to userspace :D
 * 
 * @param ip 
 * @param sp 
 * @param ... 
 */
void jmp_to_userspace(uintptr_t ip, uintptr_t sp, ...);

/**
 * @brief Manage page fault
 * 
 * @param r 
 */
void page_fault(interrupt_frame *r);

/**
 * @brief Manage generic exception
 * 
 * @param r 
 */
void generic_exception(interrupt_frame *r);

/**
 * @brief Handle syscalls
 * 
 * @param r 
 */
void syscall_handler(interrupt_frame *r);

#endif
