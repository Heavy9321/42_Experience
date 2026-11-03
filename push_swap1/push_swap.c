/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:40:51 by kasen             #+#    #+#             */
/*   Updated: 2026/11/03 15:40:54 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_parsers(int ac, char **av, t_opt *opt, t_stack **stack_a)
{
	int	start_index;

	start_index = parse_params(ac, av, opt);
	if (start_index == -1)
		return (-1);
	if (!parse_input(ac, av, start_index, stack_a)
		|| !rank_stack(*stack_a))
		return (-1);
	return (0);
}

static void	select_method(t_opt *opt)
{
	if (opt->disorder < 0.2)
		opt->method = 1;
	else if (opt->disorder < 0.5)
		opt->method = 2;
	else
		opt->method = 3;
}

static void	run_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt)
{
	opt->disorder = get_disorder(*stack_a);
	if (opt->adaptive == 1)
		select_method(opt);
	if (is_sorted(*stack_a))
		return ;
	if (stack_size(*stack_a) <= 5)
	{
		small_sort(stack_a, stack_b, opt);
		return ;
	}
	if (opt->method == 1)
		simple_sort(stack_a, stack_b, opt);
	else if (opt->method == 2)
		medium_sort(stack_a, stack_b, opt);
	else
		complex_sort(stack_a, stack_b, opt);
}

static void	init_bench(t_opt *opt)
{
	opt->bench.total = 0;
	opt->bench.sa = 0;
	opt->bench.sb = 0;
	opt->bench.ss = 0;
	opt->bench.pa = 0;
	opt->bench.pb = 0;
	opt->bench.ra = 0;
	opt->bench.rb = 0;
	opt->bench.rr = 0;
	opt->bench.rra = 0;
	opt->bench.rrb = 0;
	opt->bench.rrr = 0;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_opt	opt;

	stack_a = NULL;
	stack_b = NULL;
	init_bench(&opt);
	if (ac < 2)
		return (0);
	if (run_parsers(ac, av, &opt, &stack_a) == -1)
	{
		ft_printf("Error\n", 2);
		clear_stack(&stack_a);
		return (1);
	}
	run_sort(&stack_a, &stack_b, &opt);
	if (opt.benchmark == 1)
		write_bench(&opt);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
