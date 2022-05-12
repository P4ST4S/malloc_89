/**
 * @file malloc.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief my own malloc
 * @version 0.1
 * @date 11-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "malloc.h"
#include <unistd.h>

void *base = NULL;

t_block *find_block(t_block **last, size_t size)
{
    t_block *block = base;

    while (block && !(block->free && block->size >= size))
    {
        *last = block;
        block = block->next;
    }
    return (block);
}

t_block *extend_heap(t_block *last, size_t size)
{
    t_block *block;

    block = sbrk(0);
    if (sbrk(BLOCK_SIZE + size) == (void *)-1)
        return (NULL);
    block->size = size;
    block->next = NULL;
    block->prev = last;
    block->ptr = block->data;
    if (last)
        last->next = block;
    block->free = 0;
    return (block);
}

void split_block(t_block *block, size_t size)
{
    t_block *new;

    new = (t_block *)block->data + size;
    new->size = block->size - size - BLOCK_SIZE;
    new->next = block->next;
    new->prev = block;
    new->free = 1;
    new->ptr = new->data;
    block->size = size;
    block->next = new;
    if (new->next)
        new->next->prev = new;
}

t_block *merge(t_block *block)
{
    if (block->next && block->next->free)
    {
        block->size += BLOCK_SIZE + block->next->size;
        block->next = block->next->next;
        if (block->next)
            block->next->prev = block;
    }
    return (block);
}

t_block *get_block(void *ptr)
{
    char *tmp;
    tmp = ptr;
    return (ptr = tmp -= BLOCK_SIZE);
}

int valid_addr(void *ptr)
{
    if (base)
        if (ptr > base && ptr < sbrk(0))
            return (ptr == (get_block(ptr))->ptr);
    return (0);
}

// void copy_block(t_block *src, t_block *dest)
// {
//     int *srcData, *destData;
//     size_t loop = 0;

//     srcData = src->ptr;
//     destData = dest->ptr;
//     while (loop * 4 < src->size && loop * 4 < dest->size)
//     {
//         destData[loop] = srcData[loop];
//         loop++;
//     }
// }

void *malloc(size_t size)
{
    t_block *block, *last;
    size_t s;

    s = ALIGNONFOUR(size);
    if (base)
    {
        last = base;
        block = find_block(&last, s);
        if (block)
        {
            if ((block->size - s) >= (BLOCK_SIZE + 4))
                split_block(block, s);
            block->free = 0;
        }
        else
        {
            block = extend_heap(last, s);
            if (!block)
                return (NULL);
        }
    }
    else
    {
        block = extend_heap(NULL, s);
        if (!block)
            return (NULL);
        base = block;
    }
    return (block->data);
}

void free(void *ptr)
{
    t_block *block;

    if (valid_addr(ptr))
    {
        block = get_block(ptr);
        block->free = 1;
        if (block->prev && block->prev->free)
            block = merge(block->prev);
        if (block->next)
            merge(block->next);
        else
        {
            if (block->prev)
                block->prev->next = NULL;
            else
                base = NULL;
            brk(ptr);
        }
    }
}

void *calloc(size_t nmemb, size_t size)
{
    size_t *new;
    size_t s4, loop = 0;

    new = malloc(nmemb * size);
    if (new)
    {
        s4 = ALIGNONFOUR(nmemb * size) << 2;
        while (loop < s4)
            new[loop++] = 0;
    }
    return (new);
}

void *realloc(void *ptr, size_t new_size)
{
    unsigned int old_size;
    void *new_ptr;

    if (ptr == NULL)
        return (malloc(new_size));
    old_size = malloc_usable_size(ptr);
    if (new_size <= old_size)
        return (ptr);
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (malloc(new_size));
    std_memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return (new_ptr);
}

size_t malloc_usable_size(void *ptr)
{
    return (BLOCKSIZE(MEMOFBLOCK(ptr)) - OVERHEADBLOCK);
}
