/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 11:01:49 by kasen             #+#    #+#             */
/*   Updated: 2026/09/25 14:08:07 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*gnl_bonus_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

size_t	gnl_bonus_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*gnl_bonus_strjoin(char const *s1, char const *s2)
{
	char	*alloc;
	size_t	s_len1;
	size_t	s_len2;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = gnl_bonus_strdup("");
	s_len1 = gnl_bonus_strlen(s1);
	s_len2 = gnl_bonus_strlen(s2);
	alloc = malloc((s_len1 + s_len2 + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	gnl_bonus_memcpy(alloc, s1, s_len1);
	gnl_bonus_memcpy(alloc + s_len1, s2, s_len2);
	alloc[s_len1 + s_len2] = '\0';
	return (alloc);
}

char	*gnl_bonus_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
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

char	*gnl_bonus_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	str = malloc(gnl_bonus_strlen(s1) + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
