/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:28:57 by kasen             #+#    #+#             */
/*   Updated: 2026/08/21 08:27:55 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*alloc;
	size_t	s_len1;
	size_t	s_len2;

	if (!s1 || !s2)
		return (NULL);
	s_len1 = ft_strlen(s1);
	s_len2 = ft_strlen(s2);
	alloc = malloc((s_len1 + s_len2 + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	ft_memcpy(alloc, s1, s_len1);
	ft_memcpy(alloc + s_len1, s2, s_len2);
	alloc[s_len1 + s_len2] = '\0';
	return (alloc);
}
