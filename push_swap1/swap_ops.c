/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:39:42 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:39:44 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a, t_opt *opt)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap_stack(stack_a);
	ft_printf("sa\n", 1);
	opt->bench.sa++;
}

void	sb(t_stack **stack_b, t_opt *opt)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap_stack(stack_b);
	ft_printf("sb\n", 1);
	opt->bench.sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	swapped;

	swapped = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		swap_stack(stack_a);
		swapped = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		swap_stack(stack_b);
		swapped = 1;
	}
	if (swapped)
	{
		ft_printf("ss\n", 1);
		opt->bench.ss++;
	}
}
