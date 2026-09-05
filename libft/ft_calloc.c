/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:22:51 by kasen             #+#    #+#             */
/*   Updated: 2026/09/01 23:26:35 by kasen            ###   ########.fr       */
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
