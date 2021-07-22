#pragma once
#ifndef SNX_MMAN_H
#define SNX_MMAN_H

#include <basic.h>
#include <stddef.h>
#include <stdint.h>

enum {
    PROT_READ = 1,
    PROT_WRITE = 2,
    PROT_EXEC = 4,
    PROT_NONE = 0,
};

enum {
    MAP_SHARED = 1,
    MAP_PRIVATE = 2,
};

enum {
    MAP_32BIT = 4,
    MAP_ANONYMOUS = 8,
    // others
};

#endif
