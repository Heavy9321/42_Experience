/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:43 by kasen             #+#    #+#             */
/*   Updated: 2026/08/10 14:30:47 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (s1 > s2)
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	else
		ft_memcpy(s1, s2, len);
	return (dst);
}
