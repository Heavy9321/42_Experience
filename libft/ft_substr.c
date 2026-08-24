/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:31:13 by kasen             #+#    #+#             */
/*   Updated: 2026/08/21 19:51:20 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	alloc = malloc((len + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		alloc[i] = s[start + i];
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}
// #include "stdio.h"

// int	main(void)
// {
// 	char	*s;

// 	s = ft_substr("tripouille", 1, 1);
// 	printf("%s", s);
// }
