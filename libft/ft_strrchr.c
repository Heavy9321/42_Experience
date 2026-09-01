/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:30:03 by kasen             #+#    #+#             */
/*   Updated: 2026/08/31 20:22:33 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char) c;
	i = ft_strlen(s);
	while (1)
	{
		if ((unsigned char) s[i] == uc)
			return ((char *) & s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
