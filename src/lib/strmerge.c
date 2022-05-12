/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:56
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "strmerge.h"

char *std_strmerge(char *str1, char *str2, char *str3)
{
    char *mergeChar;
    int count = 0, countMerge = 0;

    mergeChar = malloc(std_strlen(str1) + std_strlen(str2) + std_strlen(str3) + 1);
    if (!mergeChar)
        return (NULL);
    while (str1[countMerge] != '\0')
        mergeChar[count++] = str1[countMerge++];
    countMerge = 0;
    while (str2[countMerge] != '\0')
        mergeChar[count++] = str2[countMerge++];
    countMerge = 0;
    while (str3[countMerge] != '\0')
        mergeChar[count++] = str3[countMerge++];
    mergeChar[count] = '\0';
    return (mergeChar);
}