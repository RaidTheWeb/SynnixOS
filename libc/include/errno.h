#pragma once
#ifndef _ERRNO_H_
#define _ERRNO_H_

#include <stdio.h>

#include "autogenerated_errnos.h"

#define EAGAIN EWOULDBLOCK

extern const char *errno_names[];

/** @file
 * @brief Errors
 * 
 */

#ifndef _SNX
/**
 * @brief Error number
 * 
 */
extern int errno;
/**
 * @brief Printed error
 * 
 * @param message 
 */
void perror(const char *const message);

/**
 * @brief String representation of error
 * 
 * @param errno 
 * @return const char* 
 */
const char *strerror(enum errno_value errno);
#endif

#endif