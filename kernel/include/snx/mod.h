#pragma once
#ifndef SNX_MOD_H
#define SNX_MOD_H

#include <basic.h>
#include <elf.h>
#include <list.h>

/** @file
 * @brief Functions for loading and unloading kernel modules at runtime
 * 
 */

/**
 * @brief Status types for mod initialization
 * 
 */
enum modinit_status {
    MODINIT_SUCCESS,
    MODINIT_FAILURE,
};

struct mod;

/**
 * @brief Convenience struct for supplying information about a kernel module
 * 
 */
struct modinfo {
    const char *name;
    int (*init)(struct mod *);
    void (*fini)(struct mod *);
};

/**
 * @brief Basic module struct including required data
 * 
 */
struct mod {
    const char *name;
    struct modinfo *modinfo;
    elf_md *md;

    struct list deps;
    int refcnt;
    list_node node;
};

/**
 * @brief Load a kernel module by ELF file
 * 
 * @param elf 
 * @param len 
 * @return int 
 */
int load_mod(Elf_Ehdr *elf, size_t len);
int unload_mod(struct mod *mod); // unimplemented

/**
 * @brief Kernel module symbol
 * 
 */
struct mod_sym {
    const struct mod *mod;
    const Elf_Sym *sym;
};

/**
 * @brief Helper for finding an elf symbol
 * 
 * @param address 
 * @return struct mod_sym 
 */
struct mod_sym elf_find_symbol_by_address(uintptr_t address);

#endif
