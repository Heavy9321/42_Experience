/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:39:10 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:39:12 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_position(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	min = stack->index;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	pos;
	int	size;

	pos = min_position(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a, opt);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack_a, opt);
	}
	pb(stack_a, stack_b, opt);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		push_min_to_b(stack_a, stack_b, opt);
		size--;
	}
	if (size == 3)
		sort_three(stack_a, opt);
	else if (size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, opt);
	while (*stack_b)
		pa(stack_a, stack_b, opt);
}
