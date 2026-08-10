/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:41:49 by kaansen           #+#    #+#             */
/*   Updated: 2026/07/07 22:55:27 by kaansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat (char *dest, char *src)
{
	int	j;
	int	i;

	i = 0;
	while (dest[i])
	{
		i++;
		j = 0;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>

int main(void)
{
	char	dest[10] = "yapma";
	char	src[10] = "yaptım";

	ft_strcat(dest, src);
	printf("%s", dest);
}
