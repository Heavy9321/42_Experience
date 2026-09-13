/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:15:26 by kasen             #+#    #+#             */
/*   Updated: 2026/09/08 09:26:21 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*ft_new_node(int data);
t_node	*ft_lastnode(t_node *lst);
void	ft_addback(t_node **lst, t_node *new);
void	ft_addfront(t_node **lst, t_node *new);
void	ft_free_stack(t_node **lst);

#endif
