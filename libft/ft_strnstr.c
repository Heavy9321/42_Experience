/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:24 by kasen             #+#    #+#             */
/*   Updated: 2026/08/31 22:29:28 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char *) haystack);
	if (len == 0)
		return (NULL);
	h = 0;
	n = ft_strlen(needle);
	while ((h + n) <= len && haystack[h])
	{
		if (ft_strncmp(haystack + h, needle, n) == 0)
			return ((char *) & haystack[h]);
		h++;
	}
	return (NULL);
}
