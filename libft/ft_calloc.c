#include <stdlib.h>
#include "libft.h"
void *ft_calloc(size_t count, size_t size)
{
	void* alloc;

	alloc = malloc(count * size);
	if (!alloc)
	    return(NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
