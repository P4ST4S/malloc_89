/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:02
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "strdup.h"
#include "memcpy.h"
#include "strlen.h"

char *std_strdup(const char *s)
{
    size_t len;
    void *new;

    len = std_strlen(s) + 1;
    new = malloc(len);
    if (new == NULL)
        return NULL;
    std_memcpy(new, (void *)s, len);
    return ((char *)new);
}