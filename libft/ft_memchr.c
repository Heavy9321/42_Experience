#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char num;
	size_t i;
	
	str = (unsigned char *)s;
	num = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == num)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
