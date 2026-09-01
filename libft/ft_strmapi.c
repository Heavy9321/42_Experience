/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 03:47:12 by kasen             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/31 14:31:43 by kasen            ###   ########.fr       */
=======
/*   Updated: 2026/08/26 16:57:54 by kasen            ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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
