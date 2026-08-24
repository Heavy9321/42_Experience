/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstclear.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kasen <kasen@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 01:24:16 by kasen            #+#    #+#              */
/*   Updated: 2026/08/22 01:33:02 by kasen           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*count;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		count = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = count;
	}
	*lst = NULL;
}
