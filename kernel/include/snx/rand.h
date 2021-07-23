#pragma once
#ifndef SNX_RAND_H
#define SNX_RAND_H

#include <basic.h>
#include <stddef.h>
#include <stdint.h>

/** @file
 * @brief Kernel space random functions
 * 
 */

void rand_add_entropy(uint64_t entropy);
int32_t rand_get();
int rand_num( int max );
void seed_rand_num(unsigned int seed);

#endif
