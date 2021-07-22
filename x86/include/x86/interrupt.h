#pragma once
#ifndef SNX_X86_INTERRUPT_H
#define SNX_X86_INTERRUPT_H

#include <basic.h>
#include "cpu.h"

void install_isrs(void);
void enable_irqs(void);
void disable_irqs(void);
void assert_irqs_enabled(void);
void assert_irqs_disabled(void);
void c_interrupt_shim(interrupt_frame *r);

// Moves va args 1, 2, 3 to userland args 1, 2, 3
void jmp_to_userspace(uintptr_t ip, uintptr_t sp, ...);
void page_fault(interrupt_frame *r);
void generic_exception(interrupt_frame *r);
void syscall_handler(interrupt_frame *r);

#endif
