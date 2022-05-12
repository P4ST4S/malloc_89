/**
 * @file malloc.h
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief malloc header
 * @version 0.1
 * @date 11-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __MALLOC_H__
#define __MALLOC_H__

#include <sys/types.h>
#include <unistd.h>

void std_memcpy(void *dest, void *src, size_t n);

#define ALIGNONFOUR(x) (((((x)-1) >> 2) << 2) + 4)
#define BLOCK_SIZE 20

typedef struct s_block
{
    size_t size;
    struct s_block *next;
    struct s_block *prev;
    int free;
    void *ptr;
    char data[1];
} t_block;

#define OVERHEADBLOCK (2 * sizeof(size_t))
#define BLOCKSIZE(block) ((block)->size & -2)
#define MEMOFBLOCK(ptr) (struct s_block *)((char *)(ptr)-OVERHEADBLOCK)

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t new_size);
size_t malloc_usable_size(void *p);

#endif /* __MALLOC_H__ */
