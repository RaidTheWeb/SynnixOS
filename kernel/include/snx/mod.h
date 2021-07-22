#pragma once
#ifndef SNX_MOD_H
#define SNX_MOD_H

#include <basic.h>
#include <elf.h>
#include <list.h>

enum modinit_status {
    MODINIT_SUCCESS,
    MODINIT_FAILURE,
};

struct mod;

struct modinfo {
    const char *name;
    int (*init)(struct mod *);
    void (*fini)(struct mod *);
};

struct mod {
    const char *name;
    struct modinfo *modinfo;
    elf_md *md;

    struct list deps;
    int refcnt;
    list_node node;
};

int load_mod(Elf_Ehdr *elf, size_t len);
int unload_mod(struct mod *mod); // not implemented

struct mod_sym {
    const struct mod *mod;
    const Elf_Sym *sym;
};

struct mod_sym elf_find_symbol_by_address(uintptr_t address);

#endif
