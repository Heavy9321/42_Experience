/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:37:02 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:37:10 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_wrong_pairs(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*check;
	int		wrong;

	wrong = 0;
	tmp = stack;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->value > check->value)
				wrong++;
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (wrong);
}

double	get_disorder(t_stack *stack)
{
	int	size;
	int	pairs;
	int	wrong;

	size = stack_size(stack);
	if (size < 2)
		return (0);
	pairs = (size * (size - 1)) / 2;
	wrong = count_wrong_pairs(stack);
	return ((double)wrong / pairs);
}
