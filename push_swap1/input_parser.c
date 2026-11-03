/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:41:06 by kasen             #+#    #+#             */
/*   Updated: 2026/11/03 15:41:08 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	already_exists(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	parse_argument(const char *arg, t_stack **stack)
{
	int		value;
	int		count;

	count = 0;
	while (*arg)
	{
		skip_spaces(&arg);
		if (!*arg)
			break ;
		if (!parse_number(&arg, &value))
			return (0);
		if (already_exists(*stack, value) || !add_to_stack(stack, value))
			return (0);
		count++;
	}
	return (count > 0);
}

t_stack	*parse_input(int argc, char **argv, int start, t_stack **stack)
{
	int	i;

	i = start;
	while (i < argc)
	{
		if (!parse_argument(argv[i], stack))
		{
			clear_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (*stack);
}
