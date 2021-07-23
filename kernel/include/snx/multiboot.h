#pragma once
#ifndef SNX_MULTIBOOT_H
#define SNX_MULTIBOOT_H

#include <basic.h>
#include <snx/multiboot2.h>

/** @file
 * @brief Headers for Multiboot support
 * 
 */

/**
 * @brief Initialize Multiboot
 * 
 * @param mb_info 
 */
void mb_init(uintptr_t mb_info);

/**
 * @brief Find a Multiboot tag by IOF type
 * 
 * @param tag_type 
 * @return void* 
 */
void *mb_find_tag_iof_type(int tag_type);

/**
 * @brief Get Multiboot cmdline
 * 
 * @return char* 
 */
char *mb_cmdline(void);
/**
 * @brief Get Multiboot bootloader
 * 
 * @return char* 
 */
char *mb_bootloader(void);
void *mb_elf_tag(void);
void *mb_acpi_rsdp();

/**
 * @brief InitFS information `struct`
 * 
 */
struct initfs_info {
    uintptr_t base;
    uintptr_t top;
};

/**
 * @brief Obtain InitFS information
 * 
 * @return struct initfs_info 
 */
struct initfs_info mb_initfs_info(void);

/**
 * @brief Print Memory Map
 * 
 */
void mb_mmap_print(void);

/**
 * @brief Get total usable memory from Memory Map
 * 
 * @return size_t 
 */
size_t mb_mmap_total_usable(void);

/**
 * @brief Enumerate Memory Map
 * 
 * @param cb 
 */
void mb_mmap_enumerate(void (*cb)(uintptr_t, uintptr_t, int));

#endif
