#pragma once
#ifndef SNX_STRING_H
#define SNX_STRING_H

#include <basic.h>
#include <ctype.h>
#include <string.h>

/** @file
 * @brief Kernel Space String Helpers
 *  
 */

const char *str_until(const char *source, char *tok, const char *delims);

char *strcpyto(char *dest, const char *source, char delim);
char *strncpyto(char *dest, const char *source, size_t len, char delim);

#endif
