/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:24 by kasen             #+#    #+#             */
/*   Updated: 2026/08/24 15:40:41 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (!*needle)
		return ((char *) haystack);
	while (haystack[h] && h < len)
	{
		n = 0;
		while ((haystack[h + n] && haystack[h + n] == needle[n]) && len > h + n)
		{
			if (needle[n + 1] == '\0')
				return ((char *) & haystack[h]);
			n++;
		}
		h++;
	}
	return (NULL);
}
