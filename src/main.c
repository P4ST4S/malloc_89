/**
 * @file main.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief main function
 * @version 0.1
 * @date 11-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "malloc.h"
#include <assert.h>
#include <stdio.h>

int try(int input, int wanted)
{
    if (input != wanted)
        printf("\x1B[31mFAIL\033[0m\n");
    else
        printf("\x1B[32mOK\033[0m\n");
    return (input == wanted);
}

int main(void)
{
    int *ints;
    void *pos;
    int i;

    pos = sbrk(0);
    for (i = 0; i <= 10005; i++)
    {
        ints = malloc(4 * 1000 * sizeof(int));
        free(ints);
        printf("sbrk(0) == pos : ");
        if (!try(sbrk(0) == ints, 1))
            printf("sbrk(%p) != pos(%p)\n", sbrk(0), pos);
    }
    return (0);
}
