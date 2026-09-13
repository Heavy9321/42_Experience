/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:33:14 by kasen             #+#    #+#             */
/*   Updated: 2026/09/07 18:28:45 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_node	*ft_lastnode(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_addback(t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lastnode(*lst);
	last_node->next = new;
	new->prev = last_node;
}

void	ft_addfront(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

void	ft_free_stack(t_node **lst)
{
	t_node	*new;
	t_node	*next_new;

	if (!lst || !*lst)
		return ;
	new = next_new;
	while (new)
	{
		next_new = new->next;
		free(new);
		new = next_new;
	}
	*lst = NULL;
}
