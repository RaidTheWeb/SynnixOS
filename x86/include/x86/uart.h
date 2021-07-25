#pragma once
#ifndef SNX_X86_UART_H
#define SNX_X86_UART_H

#include <basic.h>
#include <x86/cpu.h>

/** @file
 * @brief UART (COM) header files 
 * 
 */

/**
 * @brief Serial 1
 * 
 */
#define COM1 (port_addr_t)0x3f8

/**
 * @brief Serial 2
 * 
 */
#define COM2 (port_addr_t)0x2f8

/**
 * @brief Serial 3
 * 
 */
#define COM3 (port_addr_t)0x3e8

/**
 * @brief Serial 4
 * 
 */
#define COM4 (port_addr_t)0x2e8

/**
 * @brief Initialize UART
 * 
 */
void x86_uart_init(void);

/**
 * @brief Write buffer to port
 * 
 * @param p 
 * @param buf 
 * @param len 
 */
void x86_uart_write(port_addr_t p, const char *buf, size_t len);

/**
 * @brief Write byte to port
 * 
 * @param p 
 * @param b 
 */
void x86_uart_write_byte(port_addr_t p, const char b);

/**
 * @brief Read byte from port
 * 
 * @param com 
 * @return char 
 */
char x86_uart_read_byte(port_addr_t com);

/**
 * @brief Enable UART interrupts on port
 * 
 * @param com 
 */
void x86_uart_enable_interrupt(port_addr_t com);

/**
 * @brief Disable UART interrupts on port
 * 
 * @param com 
 */
void x86_uart_disable_interrupt(port_addr_t com);

#endif
