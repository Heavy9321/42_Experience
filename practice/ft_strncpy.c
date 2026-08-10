/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:27:20 by kaansen           #+#    #+#             */
/*   Updated: 2026/07/08 09:29:41 by kaansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	// while src is not over and the counter is smaller than n
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	// If the N is greater than dest, it's necessary to put the null in all the remaining indices
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char	dest[] = "######";
	char	src[] = "Source";
	int	n = 2;
	
	printf("dest before: %s\n", dest);
	ft_strncpy(dest, src, n);
	printf("dest after: %s\n", dest);
}
