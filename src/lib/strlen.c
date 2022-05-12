/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:59
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "strlen.h"

size_t std_strlen(const char *str)
{
    int lenghtCaracter;

    lenghtCaracter = 0;
    while (str[lenghtCaracter] != '\0')
        lenghtCaracter++;
    return (lenghtCaracter);
}
