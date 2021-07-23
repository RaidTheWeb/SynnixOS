#pragma once
#ifndef SNX_DMGR_H
#define SNX_DMGR_H

#include <basic.h>
#include <snx/mutex.h>

/** @file
 * @brief DMGR helpers 
 * 
 */

struct dmgr {
    int cap;
    void **data;
    kmutex lock;
};

void dmgr_init(struct dmgr *d);
int dmgr_insert(struct dmgr *d, void *ptr);
void *dmgr_get(struct dmgr *d, int handle);

//void *dmgr_swap(struct dmgr *d, int handle, void *newptr);
void *dmgr_set(struct dmgr *d, int handle, void *newptr);
void *dmgr_drop(struct dmgr *d, int handle);
void dmgr_foreach(struct dmgr *d, void (*func)(void *item));
void dmgr_foreachl(struct dmgr *d, void (*func)(void *item, long), long arg);
void dmgr_foreachp(struct dmgr *d, void (*func)(void *item, void *), void *arg);
void dmgr_copy(struct dmgr *child, struct dmgr *parent);
void dmgr_free(struct dmgr *d);
void dmgr_dump(struct dmgr *d);

#endif
