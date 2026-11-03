/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:38:46 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:38:49 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack **stack_a, t_stack **stack_b,
						int bit, t_opt *opt)
{
	int	count;

	count = stack_size(*stack_a);
	while (count-- > 0)
	{
		if (((*stack_a)->index >> bit) & 1)
			ra(stack_a, opt);
		else
			pb(stack_a, stack_b, opt);
	}
	while (*stack_b)
		pa(stack_a, stack_b, opt);
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	int	bits;
	int	bit;

	bits = count_bits(stack_size(*stack_a));
	bit = 0;
	while (bit < bits)
	{
		radix_pass(stack_a, stack_b, bit, opt);
		bit++;
	}
}
