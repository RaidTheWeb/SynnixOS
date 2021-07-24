#pragma once
#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

#include <limits.h>
#include <stdint.h>

/** @file
 * @brief Standard Types
 * 
 */

typedef uintptr_t size_t;
typedef intptr_t ssize_t;

typedef uint8_t u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint64_t u_int64_t;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;

typedef uintptr_t virt_addr_t;
typedef uintptr_t phys_addr_t;

typedef int pid_t;
typedef int64_t off_t;
typedef int uid_t;
typedef int gid_t;
typedef int dev_t;
typedef int64_t ino_t;
typedef int mode_t;
typedef int nlink_t;
typedef size_t blksize_t;
typedef size_t blkcnt_t;
typedef int64_t time_t;
typedef size_t socklen_t;
typedef int nfds_t;

#endif // _SYS_TYPES_H_
