#include <string.h>
#include "libft.h"
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
         unsigned char *s1;
         unsigned char *s2;
         size_t i;
 
         s1 = (unsigned char *)dst;
         s2 = (unsigned char *)src;
         i = 0;
         if (!dst && !src)
             return (NULL);
          while (i < n)
          {
             s1[i] = s2[i];
             i++;
          }
         return (dst);
 }
