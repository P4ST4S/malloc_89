/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:07
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "strcmp.h"

int std_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
        i++;
    return (str2[i] - str1[i]);
}