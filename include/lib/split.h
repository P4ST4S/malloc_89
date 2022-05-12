/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-03-22 14:05:31
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#ifndef __SPLIT_H__
#define __SPLIT_H__

#include <stdlib.h>

size_t std_strlen (const char *str);
int std_chara_founder (const char *str, char c);
char **std_split (const char *s, char separator);

#endif /* __SPLIT_H__ */