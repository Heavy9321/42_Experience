/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:38:55 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:38:58 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (2 * chunk);
}

static int	position_of_max(t_stack *stack)
{
	int	max;
	int	pos;
	int	top;

	max = stack->index;
	pos = 0;
	top = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			top = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (top);
}

static void	rotate_max_to_top(t_stack **stack_b, t_opt *opt)
{
	int	size;
	int	pos;

	pos = position_of_max(*stack_b);
	size = stack_size(*stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b, opt);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(stack_b, opt);
	}
}

static void	push_chunks(t_stack **stack_a, t_stack **stack_b,
		int chunk, t_opt *opt)
{
	int	high;
	int	count;

	high = chunk;
	while (*stack_a)
	{
		count = stack_size(*stack_a);
		while (count-- > 0)
		{
			if ((*stack_a)->index < high)
			{
				pb(stack_a, stack_b, opt);
				if ((*stack_b)->index < high - chunk / 2)
					rb(stack_b, opt);
			}
			else
				ra(stack_a, opt);
		}
		high += chunk;
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	chunk;

	if (stack_size(*stack_a) < 2)
		return ;
	chunk = get_chunk_size(stack_size(*stack_a));
	push_chunks(stack_a, stack_b, chunk, opt);
	while (*stack_b)
	{
		rotate_max_to_top(stack_b, opt);
		pa(stack_a, stack_b, opt);
	}
}
