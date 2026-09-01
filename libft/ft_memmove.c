/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:43 by kasen             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/30 16:52:34 by kasen            ###   ########.fr       */
=======
/*   Updated: 2026/08/27 14:38:26 by kasen            ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (s1 > s2)
	{
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	else
		ft_memcpy(s1, s2, len);
	return (dst);
}
