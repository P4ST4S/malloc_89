/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:16
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "split.h"
#include <stdio.h>

static size_t counterOfToken(const char *s, char separator)
{
    size_t count = 0, counterSpace = 0;

    while (s[count++] != '\0')
    {
        if (s[count] == separator)
            counterSpace++;
    }
    return (counterSpace);
}

char **std_split(const char *s, char separator)
{
    char **splitTab;
    size_t countLilTab = 0, countBigTab = 0, countStr = 0, counterSpace = counterOfToken(s, separator);

    splitTab = malloc(sizeof(char *) * (counterSpace + 2));
    if (!splitTab)
        return (NULL);
    splitTab[countBigTab] = malloc(std_strlen(s) + 1);
    if (!splitTab[countBigTab])
        return (NULL);
    while (s[countStr] != '\0')
    {
        splitTab[countBigTab][countLilTab++] = s[countStr++];
        if (s[countStr] == separator || s[countStr] == '\0')
        {
            splitTab[countBigTab++][countLilTab] = '\0';
            countLilTab = '\0';
            if (s[countStr] != '\0')
                countStr++;
            splitTab[countBigTab] = malloc(sizeof(char) * 32);
        }
    }
    splitTab[countBigTab] = NULL;
    return (splitTab);
}
