/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:39:02 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:39:04 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *stack)
{
	int	min;
	int	min_pos;
	int	pos;

	min = stack->value;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_top(t_stack **stack_a, t_opt *opt)
{
	int	pos;
	int	size;

	pos = find_min_pos(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack_a, opt);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack_a, opt);
	}
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	while (!is_sorted(*stack_a))
	{
		move_min_top(stack_a, opt);
		pb(stack_a, stack_b, opt);
	}
	while (*stack_b)
		pa(stack_a, stack_b, opt);
}
