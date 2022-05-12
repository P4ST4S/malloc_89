/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:04
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "strcpy.h"

char *std_strcpy(char *dest,
                 const char *src)
{
    int count;

    count = 0;
    while (src[count] != '\0')
    {
        dest[count] = src[count];
        count++;
    }
    dest[count++] = '\0';
    return (dest);
}