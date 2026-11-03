/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:38:37 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:38:40 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack_a, t_opt *opt)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate_stack(stack_a);
	ft_printf("ra\n", 1);
	opt->bench.ra++;
}

void	rb(t_stack **stack_b, t_opt *opt)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate_stack(stack_b);
	ft_printf("rb\n", 1);
	opt->bench.rb++;
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	rotated;

	rotated = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		rotate_stack(stack_a);
		rotated = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		rotate_stack(stack_b);
		rotated = 1;
	}
	if (rotated)
	{
		ft_printf("rr\n", 1);
		opt->bench.rr++;
	}
}
