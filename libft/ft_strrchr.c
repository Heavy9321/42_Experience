/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:30:03 by kasen             #+#    #+#             */
/*   Updated: 2026/09/01 19:26:07 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	uc;

	if (!s)
		return (NULL);
	uc = (char) c;
	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == uc)
			return ((char *) & s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
