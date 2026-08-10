#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned int i;

	ptr = (unsigned char *)b;
	i = 0;

	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
