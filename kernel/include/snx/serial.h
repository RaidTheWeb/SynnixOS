#pragma once
#ifndef SNX_SERIAL_H
#define SNX_SERIAL_H

#include <basic.h>

/** @file
 * @brief Serial support
 * 
 */

/**
 * @brief Initialize serial drivers
 * 
 */
void serial_init(void);

/**
 * @brief Write character to serial COM1
 * 
 * @param c 
 */
void serial_write(const char c);

/**
 * @brief Write string to serial COM1 
 * Wrapper around `serial_write` to print a string to COM1
 * @param buf 
 * @param len 
 */
void serial_write_str(const char *buf, size_t len);

/**
 * @brief Read character from serial COM1
 * 
 * @return char 
 */
char serial_read(void);

/**
 * @brief Write character to serial COM2
 * 
 * @param c 
 */
void serial2_write(const char c);

/**
 * @brief Write string to serial COM2
 * Wrapper around `serial2_write` to write a string to serial COM2
 * @param buf 
 * @param len 
 */
void serial2_write_str(const char *buf, size_t len);

/**
 * @brief Read character from serial COM2
 * 
 * @return char 
 */
char serial2_read(void);

/**
 * @brief Read character from serial COM1
 * 
 * @return char 
 */
char serial_read(void);

/**
 * @brief Write character to serial COM2
 * 
 * @param c 
 */
void serial2_write(const char c);

/**
 * @brief Write string to serial COM2
 * Wrapper around `serial2_write` to write a string to serial COM2
 * @param buf 
 * @param len 
 */
void serial2_write_str(const char *buf, size_t len);

/**
 * @brief Read character from serial COM2
 * 
 * @return char 
 */
char serial2_read(void);

/**
 * @brief Write character to serial COM3
 * 
 * @param c 
 */
void serial3_write(const char c);

/**
 * @brief Write string to serial COM3
 * Wrapper around `serial3_write` to write a string to serial COM3
 * @param buf 
 * @param len 
 */
void serial3_write_str(const char *buf, size_t len);

/**
 * @brief Read character from serial COM3
 * 
 * @return char 
 */
char serial3_read(void);

/**
 * @brief Write character to serial COM4
 * 
 * @param c 
 */
void serial4_write(const char c);

/**
 * @brief Write string to serial COM4
 * Wrapper around `serial4_write` to write a string to serial COM4
 * @param buf 
 * @param len 
 */
void serial4_write_str(const char *buf, size_t len);

/**
 * @brief Read character from serial COM4
 * 
 * @return char 
 */
char serial4_read(void);

#endif
