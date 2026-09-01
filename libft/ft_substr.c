/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:31:13 by kasen             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/30 10:44:16 by kasen            ###   ########.fr       */
=======
/*   Updated: 2026/08/28 19:25:06 by kasen            ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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
<<<<<<< HEAD
=======
#include "stdio.h"

int	main(void)
{
	char	*s;

	s = ft_substr("42", 400, 0);
	printf("%s", s);
}
>>>>>>> refs/remotes/origin/main
