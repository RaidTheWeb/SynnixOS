#pragma once
#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

/** @file Directory Entries
 * @brief 
 * 
 */

/**
 * @brief Directory entry struct
 * 
 */
struct snx_dirent {
    enum file_type type;
    enum file_mode mode;
    char name[64];
};

#ifndef __kernel__
/**
 * @brief Get directory entries
 * 
 * @param fd 
 * @param buf 
 * @param count 
 * @return ssize_t 
 */
ssize_t getdirents(int fd, struct snx_dirent *buf, size_t count);

/**
 * @brief Read directory
 * 
 * @param fd 
 * @param buf 
 * @param count 
 * @return ssize_t 
 */
ssize_t readdir(int fd, struct snx_dirent *buf, size_t count);
#endif

#endif // _DIRENT_H_
