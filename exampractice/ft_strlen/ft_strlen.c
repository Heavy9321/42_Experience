/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:24:20 by kaansen           #+#    #+#             */
/*   Updated: 2026/07/02 22:42:31 by kaansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	b;

	b = 0;
	while (str[b] != '\0')
	{
		b++;
	}
	return(b);
}

int main()
{
	char *str = "hello";

	int s;

	s = ft_strlen(str);
	printf("String %s\nLength %d\n", str, s);
}
