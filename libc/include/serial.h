#pragma once
#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <syscall.h>
#include <stddef.h>
#include <unistd.h>
#include <basic.h>

/** @file
 * @brief User-space serial library (SynnixOS Exclusive) 
 * Wrapper library around serial syscalls
 */

#define COM1 0x3f8
#define COM2 0x2f8
#define COM3 0x3e8
#define COM4 0x2e8

/** 
 * @brief Write byte to serial port
 * 
 * @param port 
 * @param byte 
 * @return int 
 */
int computb(int port, char byte);

/**
 * @brief Write string buffer to serial port
 * 
 * @param port 
 * @param buffer 
 * @return int 
 */
int computs(int port, const char* buffer, size_t len);

/**
 * @brief Read byte from serial port
 * 
 * @param port 
 * @return char 
 */
char comgetb(int port);

/**
 * @brief Read string from serial port, cut off at newline
 * 
 * @param port 
 * @return char* 
 */
char* comgets(int port);

/**
 * @brief Read string from serial port and echo input
 * 
 * @param port 
 * @return char* 
 */
char* comgetse(int port);

#endif // _SERIAL_H_