/**
 * @ Author: Your name
 * @ Create Time: 2022-03-15 10:47:36
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-03-23 15:53:30
 * @ Copyright: Antoine ROSPARS - All Rights Reserved - 2022
 */

#ifndef __ITOA_H__
#define __ITOA_H__

#define swap(a, b)                                                            \
  ((&(a) == &(b)) ? (a) : ((a) ^= (b), (b) ^= (a), (a) ^= (b)))

#include <stdbool.h>

char *itoa (int num, char *str, int base);

#endif /* __ITOA_H__ */