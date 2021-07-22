#pragma once
#ifndef SNX_PMM_H
#define SNX_PMM_H

#include <basic.h>
#include <sys/types.h>

#define PM_NOMEM 0
#define PM_LEAK 1
#define PM_REF_BASE 2
#define PM_REF_ZERO PM_REF_BASE

// int pm_getref(phys_addr_t pma);
int pm_incref(phys_addr_t pma);
int pm_decref(phys_addr_t pma);
phys_addr_t pm_alloc(void);
void pm_free(phys_addr_t);
void pm_set(phys_addr_t base, phys_addr_t top, uint8_t set_to);

struct open_file;
void pm_summary(struct open_file *, void *);

#endif
