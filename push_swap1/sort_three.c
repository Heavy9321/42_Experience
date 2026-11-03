/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:39:17 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:39:19 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_a_first(t_stack **stack_a, t_opt *opt)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (b > c)
	{
		sa(stack_a, opt);
		rra(stack_a, opt);
	}
	else if (a > c)
		ra(stack_a, opt);
	else
		sa(stack_a, opt);
}

static void	sort_three_b_first(t_stack **stack_a, t_opt *opt)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > c)
		rra(stack_a, opt);
	else if (b > c)
	{
		rra(stack_a, opt);
		sa(stack_a, opt);
	}
}

void	sort_three(t_stack **stack_a, t_opt *opt)
{
	int	a;

	a = (*stack_a)->index;
	if (a > (*stack_a)->next->index)
		sort_three_a_first(stack_a, opt);
	else
		sort_three_b_first(stack_a, opt);
}
