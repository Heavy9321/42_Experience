/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:36:35 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:36:40 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_complexity(t_opt *opt)
{
	if (opt->method == 1)
		ft_printf("O(n^2)\n", 2);
	else if (opt->method == 2)
		ft_printf("O(n√n)\n", 2);
	else if (opt->method == 3)
		ft_printf("O(n log n)\n", 2);
}

static void	write_strategy(t_opt *opt)
{
	if (opt->adaptive == 1)
	{
		ft_printf("[bench] strategy: Adaptive / ", 2);
		write_complexity(opt);
		return ;
	}
	else if (opt->method == 1)
		ft_printf("[bench] strategy: Simple / ", 2);
	else if (opt->method == 2)
		ft_printf("[bench] strategy: Medium / ", 2);
	else if (opt->method == 3)
		ft_printf("[bench] strategy: Complex / ", 2);
	write_complexity(opt);
}

void	set_total(t_opt *opt)
{
	opt->bench.total = opt->bench.sa + opt->bench.sb + opt->bench.ss
		+ opt->bench.pa + opt->bench.pb + opt->bench.ra + opt->bench.rb
		+ opt->bench.rr + opt->bench.rra + opt->bench.rrb + opt->bench.rrr;
}

static void	write_disorder(t_opt *opt)
{
	int	percent;

	percent = (int)(opt->disorder * 10000 + 0.5);
	ft_printf("[bench] disorder: %d.", 2, percent / 100);
	if (percent % 100 < 10)
		ft_printf("0", 2);
	ft_printf("%d%%\n", 2, percent % 100);
}

void	write_bench(t_opt *opt)
{
	set_total(opt);
	write_disorder(opt);
	write_strategy(opt);
	ft_printf("[bench] total_ops: %d\n", 2, opt->bench.total);
	ft_printf("[bench] sa: %d\n", 2, opt->bench.sa);
	ft_printf("[bench] sb: %d\n", 2, opt->bench.sb);
	ft_printf("[bench] ss: %d\n", 2, opt->bench.ss);
	ft_printf("[bench] pa: %d\n", 2, opt->bench.pa);
	ft_printf("[bench] pb: %d\n", 2, opt->bench.pb);
	ft_printf("[bench] ra: %d\n", 2, opt->bench.ra);
	ft_printf("[bench] rb: %d\n", 2, opt->bench.rb);
	ft_printf("[bench] rr: %d\n", 2, opt->bench.rr);
	ft_printf("[bench] rra: %d\n", 2, opt->bench.rra);
	ft_printf("[bench] rrb: %d\n", 2, opt->bench.rrb);
	ft_printf("[bench] rrr: %d\n", 2, opt->bench.rrr);
}
