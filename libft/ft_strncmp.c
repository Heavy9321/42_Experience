/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:54:12 by kasen             #+#    #+#             */
/*   Updated: 2026/08/20 20:27:12 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] == s2[a] && a < n - 1 && s1[a] != '\0')
		a++;
	return ((unsigned char) s1[a] - (unsigned char) s2[a]);
}
