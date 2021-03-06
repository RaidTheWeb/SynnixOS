#pragma once
#ifndef SNX_VMM_H
#define SNX_VMM_H

#include <basic.h>

enum fault_result {
    FAULT_CRASH,
    FAULT_CONTINUE,
};

#if X86
#include <x86/vmm.h>
#endif

void *vmm_reserve(size_t);
void *high_vmm_reserve(size_t);

#endif
