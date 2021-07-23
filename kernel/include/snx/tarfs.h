#pragma once
#ifndef SNX_TARFS_H
#define SNX_TARFS_H

#include <basic.h>
#include <stddef.h>
#include <stdint.h>

/** @file
 * @brief Tar file read support
 * 
 */

/**
 * @brief Tar file header struct
 * 
 */
struct tar_header {
    char filename[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char chksum[8];
    char typeflag;
};

/**
 * @brief Tar typing flags
 * 
 */
enum tar_typeflag {
    REGTYPE = '0',
    AREGTYPE = '\0',
    LNKTYPE = '1',
    CHRTYPE = '3',
    BLKTYPE = '4',
    DIRTYPE = '5',
    FIFOTYPE = '6',
};

/**
 * @brief Convert number into 64 bit unsigned integer
 * 
 * @param num 
 * @return uint64_t 
 */
uint64_t tar_convert_number(char *num);

/**
 * @brief Print all tar files
 * 
 * @param tar 
 */
void tarfs_print_all_files(struct tar_header *tar);

/**
 * @brief Get a file from tar
 * 
 * @param tar 
 * @param filename 
 * @return void* 
 */
void *tarfs_get_file(struct tar_header *tar, const char *filename);

/**
 * @brief Get length of file in tar
 * 
 * @param tar 
 * @param filename 
 * @return size_t 
 */
size_t tarfs_get_len(struct tar_header *tar, const char *filename);

#endif
