#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	void	*content;
	struct	s_list *next;
}	t_list;

size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t  ft_strlen(const char *s);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    *ft_memset(void *b, int c, size_t len);
void *ft_memmove(void *dst, const void *src, size_t len);

#endif


