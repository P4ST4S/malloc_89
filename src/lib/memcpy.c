/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:18
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "memcpy.h"

void std_memcpy(void *dest,
                void *src,
                size_t n)
{
    size_t loop;
    char *chain_src;
    char *chain_dest;

    loop = 0;
    chain_src = (char *)src;
    chain_dest = (char *)dest;
    while (loop < n)
    {
        chain_dest[loop] = chain_src[loop];
        loop++;
    }
}