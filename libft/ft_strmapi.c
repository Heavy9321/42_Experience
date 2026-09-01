/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 03:47:12 by kasen             #+#    #+#             */
/*   Updated: 2026/09/01 08:06:34 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*alloc;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	alloc = malloc(((ft_strlen(s) + 1) * sizeof(char)));
	if (!alloc)
		return (NULL);
	while (s[i] != '\0')
	{
		alloc[i] = f(i, s[i]);
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}
