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

int main(void)
{
    char *str = malloc(10);

    str[0] = 'B';
    str[1] = 'o';
    str[2] = 'n';
    str[3] = 'j';
    str[4] = 'o';
    str[5] = 'u';
    str[6] = 'r';
    str[7] = ' ';
    str[8] = ' ';
    str[9] = ' ';
    str[10] = ' ';
    str[11] = ' ';

    printf("%s\n", str);
    free(str);
    return (0);
}