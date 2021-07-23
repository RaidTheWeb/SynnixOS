#pragma once
#ifndef SNX_RINGBUF_H
#define SNX_RINGBUF_H

#include <basic.h>
#include <stddef.h>
#include <stdint.h>

/** @file
 * @brief Ring Buffers
 * 
 */

/**
 * @brief Ring Buffer structure
 * 
 */
struct ringbuf {
    char *data;

    size_t size;
    size_t len;
    size_t head;
};

/**
 * @brief Create new Ring Buffer
 * 
 * @param size 
 * @return struct ringbuf* 
 */
struct ringbuf *new_ring(size_t size);
void emplace_ring(struct ringbuf *ring, size_t size);
/**
 * @brief Free a Ring Buffer
 * 
 */
void free_ring(struct ringbuf *);
/**
 * @brief Write data to Ring Buffer
 * 
 * @param data 
 * @param len 
 * @return size_t 
 */
size_t ring_write(struct ringbuf *, const void *data, size_t len);
/**
 * @brief Read data from Ring Buffer
 * 
 * @param data 
 * @param len 
 * @return size_t 
 */
size_t ring_read(struct ringbuf *, void *data, size_t len);

/**
 * @brief Alias emplace_ring to ring_emplace
 * 
 */
#define ring_emplace emplace_ring

#endif
