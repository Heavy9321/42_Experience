/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 21:15:34 by kasen             #+#    #+#             */
/*   Updated: 2026/08/24 15:34:10 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_write_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free_all(char **arr, int b)
{
	while (b > 0)
		free(arr[--b]);
	free(arr);
	return (NULL);
}

static char	ft_split_add(char const *s, int *i, char c, char **split)
{
	*split = ft_write_word(&s[*i], c);
	if (!*split)
		return (-1);
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**alloc;
	int		i1;
	int		i2;

	if (!s)
		return (NULL);
	alloc = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!alloc)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s[i1])
	{
		if (s[i1] == c)
			i1++;
		else if (ft_split_add(s, &i1, c, &alloc[i2++]) == -1)
			return (ft_free_all(alloc, i2), NULL);
	}
	alloc[i2] = NULL;
	return (alloc);
}
