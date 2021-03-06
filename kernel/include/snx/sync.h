#pragma once
#ifndef SNX_SYNC_H
#define SNX_SYNC_H

#include <basic.h>
#include <list.h>
#include <stdatomic.h>

/** @file
 * @brief Synchronous Threading helpers
 * 
 */

/**
 * @brief Queue struct
 * 
 */
struct wq {
    list_head queue; // struct thread.wait_node
};

/**
 * @brief Initialize queue
 * 
 */
#define WQ_INIT(name)                                                          \
    { .queue = LIST_INIT(name.queue) }

struct condvar {
    struct wq wq;
};

#define CV_INIT(name)                                                          \
    { .wq = WQ_INIT(name.wq) }

/**
 * @brief MUTEX structure
 * 
 */
struct mutex {
    struct wq wq;
    atomic_int state;
};

#define MTX_INIT(name)                                                         \
    { .wq = WQ_INIT(name.wq), 0 }
#define MTX_CLEAR(name)                                                        \
    do {                                                                       \
        list_init(&(name)->wq.queue);                                          \
        (name)->state = 0;                                                     \
    } while (0)

#define MUTEX_INIT MTX_INIT
#define MUTEX_CLEAR MTX_CLEAR

struct sem {
    struct wq wq;
    atomic_int count;
};

#define SEM_INIT(name)                                                         \
    { .wq = WQ_INIT, .count = 0 }

//

// // // // //

/**
 * @brief Initialize Queue
 * 
 * @param wq 
 */
void wq_init(struct wq *wq);

/**
 * @brief Block queue
 * 
 * @param wq 
 */
void wq_block_on(struct wq *wq);

/**
 * @brief Notify queue
 * 
 * @param wq 
 */
void wq_notify_one(struct wq *wq);

/**
 * @brief Notify whole queue
 * 
 * @param wq 
 */
void wq_notify_all(struct wq *wq);
void cv_wait(struct condvar *cv, struct mutex *mtx);
void cv_signal(struct condvar *cv);
void cv_broadcast(struct condvar *cv);
int mtx_try_lock(struct mutex *mtx);
void mtx_lock(struct mutex *mtx);
void mtx_unlock(struct mutex *mtx);

#define with_lock(l) BRACKET(mtx_lock(l), mtx_unlock(l))

#endif
