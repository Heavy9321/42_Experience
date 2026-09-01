/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 19:23:54 by kasen             #+#    #+#             */
/*   Updated: 2026/09/01 08:06:23 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	length(long b)
{
	int	c;

	c = 0;
	if (b < 0)
	{
		c++;
		b = -b;
	}
	else if (b == 0)
		return (1);
	while (b > 0)
	{
		c++;
		b = (b / 10);
	}
	return (c);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*alloc;

	i = n;
	len = length(i);
	alloc = malloc((len + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	alloc[len] = '\0';
	if ((i < 0))
	{
		alloc[0] = '-';
		i = -i;
	}
	if (i == 0)
		alloc[0] = '0';
	while (i > 0)
	{
		alloc[len - 1] = (i % 10) + '0';
		i = i / 10;
		len--;
	}
	return (alloc);
}
