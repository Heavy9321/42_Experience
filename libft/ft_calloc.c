/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:51 by kasen             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/31 14:34:48 by kasen            ###   ########.fr       */
=======
/*   Updated: 2026/08/28 17:32:36 by kasen            ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (size != 0 && count > ((size_t) - 1) / size)
		return (NULL);
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, count * size);
	return (alloc);
}
