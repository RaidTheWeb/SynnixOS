#include <basic.h>
#include <snx/panic.h>
#include <snx/ringbuf.h>
#include <snx/string.h>
#include <stdlib.h>

struct ringbuf *new_ring(size_t size) {
    struct ringbuf *ring = malloc(sizeof(struct ringbuf));
    ring->data = malloc(size);
    ring->size = size;
    ring->len = 0;
    ring->head = 0;
    return ring;
}

void emplace_ring(struct ringbuf *ring, size_t size) {
    ring->data = malloc(size);
    ring->size = size;
    ring->len = 0;
    ring->head = 0;
}

void free_ring(struct ringbuf *ring) {
    if (ring->data) free(ring->data);
}

size_t ring_write(struct ringbuf *r, const void *data, size_t len) {
    if (r->head > r->len) {
        size_t count = umin(len, r->size - r->head);
        memcpy(r->data + r->head, data, count);
        r->head += count;
        r->len += count;
        r->head %= r->size; // 0 if at ->size

        if (count < len) {
            count += ring_write(r, (const char *)data + count, len - count);
        }
        return count;
    }

    if (r->head <= r->len) {
        size_t count = umin(len, r->size - r->len);
        memcpy(r->data + r->head, data, count);
        r->head += count;
        r->len += count;
        r->head %= r->size;
        return count;
    }

    panic("idk man, I think we raced the ring :0");
}

size_t ring_read(struct ringbuf *r, void *data, size_t len) {
    if (r->len == 0) return 0;

    if (r->head >= r->len) {
        size_t count = umin(len, r->len);
        memcpy(data, r->data + r->head - r->len, count);
        r->len -= count;
        return count;
    }

    if (r->head < r->len) {
        size_t count = umin(len, r->len - r->head);
        memcpy(data, r->data + r->size - r->len + r->head, count);
        r->len -= count;
        if (count < len) {
            count += ring_read(r, (char *)data + count, len - count);
        }
        return count;
    }
    panic("Bro we raced the ring!");
}
