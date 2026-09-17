/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:06:15 by kasen             #+#    #+#             */
/*   Updated: 2026/09/17 01:26:47 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
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

size_t	gnl_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	alloc = malloc((len + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		alloc[i] = s[start + i];
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) & s[i]);
	return (NULL);
}
