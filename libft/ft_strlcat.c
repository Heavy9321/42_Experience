/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kasen <kasen@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/10 14:22:38 by kasen            #+#    #+#              */
/*   Updated: 2026/08/11 15:42:55 by kasen           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i1;
	size_t	i2;

	i2 = 0;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i1 = ft_strlen(dst);
	while (src[i2] && i1 + 1 < dstsize)
	{
		dst[i1] = src[i2];
		i1++;
		i2++;
	}
	dst[i1] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i2]));
}
