/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:38:27 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:38:29 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, t_opt *opt)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	reverse_rotate_stack(stack_a);
	ft_printf("rra\n", 1);
	opt->bench.rra++;
}

void	rrb(t_stack **stack_b, t_opt *opt)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate_stack(stack_b);
	ft_printf("rrb\n", 1);
	opt->bench.rrb++;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	rotated;

	rotated = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		reverse_rotate_stack(stack_a);
		rotated = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		reverse_rotate_stack(stack_b);
		rotated = 1;
	}
	if (rotated)
	{
		ft_printf("rrr\n", 1);
		opt->bench.rrr++;
	}
}
