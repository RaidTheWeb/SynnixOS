#pragma once
#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <basic.h>
#include <list.h>
#include <stdnoreturn.h>

#if __kernel__
#include <snx/mutex.h>
#endif

#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (1)

#define RAND_MAX 0xFFFFFFFF

#define ATEXIT_MAX 32

#define HEAP_MINIMUM_BLOCK 16
#define HEAP_MINIMUM_ALIGN 16

/** @file
 * @brief Standard library
 * 
 */


/**
 * @brief Ignore this, useless stub
 * 
 * @return int 
 */
int malloc_size();

/**
 * @brief Allocate memory
 * 
 * @param len 
 * @return void* 
 */
void *malloc(size_t len);

/**
 * @brief Free memory
 * 
 * @param alloc 
 */
void free(void *alloc);

/**
 * @brief Reallocate memory
 * 
 * @param alloc 
 * @param len 
 * @return void* 
 */
void *realloc(void *alloc, size_t len);

/**
 * @brief Allocates a block of memory for an array of num elements
 * 
 * @param count 
 * @param len 
 * @return void* 
 */
void *calloc(size_t count, size_t len);

/**
 * @brief Allocate memory
 * 
 * @param len 
 * @return void* 
 */
void *zmalloc(size_t len);

/**
 * @brief Reallocate memory
 * 
 * @return void* 
 */
void *zrealloc(void *, size_t);

/**
 * @brief Memory region
 * 
 */
struct __ALIGN(16) mregion {
    unsigned int magic_number_1;
    // const char *allocation_location;
    size_t length;
};

/**
 * @brief Free memory region
 * 
 */
struct free_mregion {
    struct mregion m;
    list_node free_node;
};

/**
 * @brief memory region
 * 
 */
typedef struct mregion mregion;

/**
 * @brief Free memory region
 * 
 */
typedef struct free_mregion free_mregion;

/**
 * @brief Memory heap
 * 
 */
struct mheap {
    list free_list;
    long allocations;
    long frees;
    size_t total_size;
    size_t free_size;
    bool is_init;
#if __kernel__
    mutex_t lock;
#endif
};

// for now I need the mregion to be N alignments wide exactly
static_assert(sizeof(struct mregion) % HEAP_MINIMUM_ALIGN == 0);

// the free list node has to fit in a minimum-sized allocation block
static_assert(sizeof(free_mregion) - sizeof(mregion) <= HEAP_MINIMUM_BLOCK);


extern struct mheap *global_heap;

void nc_malloc_init(void);
long int strtol(const char *nptr, char **endptr, int base);
long long int strtoll(const char *nptr, char **endptr, int base);
unsigned long strtoul(const char *nptr, char **endptr, int base);
unsigned long long strtoull(const char *ntr, char **endptr, int base);

#if __kernel__
#define EARLY_MALLOC_POOL_LEN 128 * KB
extern char early_malloc_pool[EARLY_MALLOC_POOL_LEN];
#endif

void heap_init(struct mheap *, void *base, size_t len);
void *heap_malloc(struct mheap *, size_t len);
void heap_free(struct mheap *, void *alloc);
void *heap_realloc(struct mheap *, void *alloc, size_t len);
void *heap_calloc(struct mheap *, size_t count, size_t len);

#ifndef _SNX

int abs(int x);
long labs(long x);
long long llabs(long long x);

struct div_t {
    int quot;
    int rem;
};
struct ldiv_t {
    long quot;
    long rem;
};
struct lldiv_t {
    long long quot;
    long long rem;
};

typedef struct div_t div_t;
typedef struct ldiv_t ldiv_t;
typedef struct lldiv_t lldiv_t;

div_t div(int x, int y);
ldiv_t ldiv(long x, long y);
lldiv_t lldiv(long long x, long long y);

char *getenv(const char *name);
void abort(void);

long int random(void);
void srandom(unsigned seed);
int rand(void);
void srand(unsigned seed);

double strtod(const char *str, char **end);
float strtof(const char *str, char **end);
long double strtold(const char *str, char **end);
int atoi(const char *nptr);
long atol(const char *nptr);
long long atoll(const char *nptr);

noreturn void _exit(int status);
noreturn void exit(int status);
noreturn void exit_group(int status);
int atexit(void (*fn)(void));

int system(const char *command);
int mkstemp(char *name);

#endif

#endif
