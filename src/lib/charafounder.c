/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:21
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "charafounder.h"

int std_chara_founder(const char *str, char c)
{
    int count = 0;

    while (str[count] != '\0')
    {
        if (str[count] == c)
            return (count);
        count++;
    }
    return (count);
}