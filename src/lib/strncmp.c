/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:52
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "strncmp.h"

int std_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0)
        return 0;
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}