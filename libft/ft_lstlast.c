/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstlast.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kasen <kasen@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 00:58:41 by kasen            #+#    #+#              */
/*   Updated: 2026/08/22 01:11:29 by kasen           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
