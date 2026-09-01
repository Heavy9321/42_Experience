/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:38 by kasen             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/31 22:06:18 by kasen            ###   ########.fr       */
=======
/*   Updated: 2026/08/27 23:56:23 by kasen            ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

<<<<<<< HEAD
	j = 0;
	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dstsize == dst_len)
		return (dstsize + src_len);
	while (src[j] && (dst_len + j) < (dstsize - 1))
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
=======
	if (!dst || !src)
		return (0);
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[j] && dst_len + 1 < dstsize)
	{
		dst[dst_len] = src[j];
		j++;
	}
	dst[dst_len] = '\0';
>>>>>>> refs/remotes/origin/main
	return (dst_len + src_len);
}
