#pragma once
#ifndef SNX_X86_CPU_H
#define SNX_X86_CPU_H

#include <basic.h>
#include <stdnoreturn.h>

#define NIRQS 16

/** @file
 * @brief CPU headers 
 * 
 */

/**
 * @brief x86 Interrupt frame
 * 
 */
typedef struct interrupt_frame {
    uint64_t ds;
    uint64_t r15, r14, r13, r12, r11, r10, r9, r8;
    uint64_t bp, rdi, rsi, rdx, rbx, rcx, rax;
    uint64_t interrupt_number, error_code;
    uint64_t ip, cs, flags, user_sp, ss;
} interrupt_frame;

#define FRAME_SYSCALL(frame) ((frame)->rax)
#define FRAME_ARG1(frame) ((frame)->rdi)
#define FRAME_ARG2(frame) ((frame)->rsi)
#define FRAME_ARG3(frame) ((frame)->rdx)
#define FRAME_ARG4(frame) ((frame)->rcx)
#define FRAME_ARG5(frame) ((frame)->r8)
#define FRAME_ARG6(frame) ((frame)->r9)
#define FRAME_RETURN(frame) ((frame)->rax)
#define FRAME_ARGC(frame) ((frame)->rdi)
#define FRAME_ARGV(frame) ((frame)->rsi)
#define FRAME_ENVP(frame) ((frame)->rdx)

/**
 * @brief Port address typedef
 * 
 */
typedef uint16_t port_addr_t;

/**
 * @brief Read 8 bit integer from port
 * 
 * @param port 
 * @return uint8_t 
 */
uint8_t inb(port_addr_t port);

/**
 * @brief Write 8 bit integer to port
 * 
 * @param port 
 * @param data 
 */
void outb(port_addr_t port, uint8_t data);

/**
 * @brief Read 16 bit integer from port
 * 
 * @param port 
 * @return uint16_t 
 */
uint16_t inw(port_addr_t port);

/**
 * @brief Write 16 bit integer to port
 * 
 * @param port 
 * @param data 
 */
void outw(port_addr_t port, uint16_t data);

/**
 * @brief Read 32 bit integer from port
 * 
 * @param port 
 * @return uint32_t 
 */
uint32_t ind(port_addr_t port);

/**
 * @brief Write 32 bit integer to port
 * 
 * @param port 
 * @param data 
 */
void outd(port_addr_t port, uint32_t data);

/**
 * @brief RDTSC function
 * 
 * @return uint64_t 
 */
uint64_t rdtsc();

/**
 * @brief Set the vm root object
 * 
 */
void set_vm_root(uintptr_t);

void invlpg(uintptr_t);
void flush_tlb(void);
uint64_t rdmsr(uint32_t msr_id);
void wrmsr(uint32_t msr_id, uint64_t value);

/**
 * @brief Enable interrupts flag
 * 
 */
#define INTERRUPT_ENABLE 0x200

/**
 * @brief Trap flag
 * 
 */
#define TRAP_FLAG 0x100

/**
 * @brief Halt CPU
 * 
 * @return noreturn 
 */
noreturn void halt();

#endif
