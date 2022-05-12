#include "atoi.h"
#include <stdio.h>

int
std_atoi (const char *nptr)
{
  int result = 0, loop = 0;

  while (nptr[loop] != '\0')
    {
      result = result * 10 + nptr[loop] - '0';
      loop++;
    }
  if (result >= MAX_INT || result <= MIN_INT)
    return (errno = EINVAL);
  return (result);
}