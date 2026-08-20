/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:31:13 by kasen             #+#    #+#             */
/*   Updated: 2026/08/18 23:24:41 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*alloc;
	unsigned int	s_len;
	char			*str;

	str = (char *) s;
	alloc = (char *) malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		len = 0;
		alloc = malloc(len + 1);
		return (ft_strdup(""));
	}
	if (len > s_len - start)
		len = s_len - start;
	ft_strlcpy(alloc, str + start, s_len + 1);
	return (alloc);
}
