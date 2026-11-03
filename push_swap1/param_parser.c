/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:41:01 by kasen             #+#    #+#             */
/*   Updated: 2026/11/03 15:41:03 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	param_cmp(const char *param, const char *arg)
{
	while (*param && *arg && *param == *arg)
	{
		param++;
		arg++;
	}
	return (*param - *arg);
}

static int	method_number(const char *arg)
{
	if (!param_cmp(arg, "--adaptive") || !param_cmp(arg, "--simple"))
		return (1);
	if (!param_cmp(arg, "--medium"))
		return (2);
	if (!param_cmp(arg, "--complex"))
		return (3);
	return (0);
}

static int	set_method_value(t_opt *opt, const char *arg)
{
	int	method;

	method = method_number(arg);
	if (!method)
		return (0);
	opt->adaptive = !param_cmp(arg, "--adaptive");
	opt->method = method;
	return (1);
}

static int	set_method(t_opt *opt, const char *arg, int *method_set)
{
	if (*method_set || !set_method_value(opt, arg))
		return (0);
	*method_set = 1;
	return (1);
}

int	parse_params(int ac, char **av, t_opt *opt)
{
	int	i;
	int	method_set;

	i = 1;
	method_set = 0;
	opt->adaptive = 1;
	opt->method = 1;
	opt->benchmark = 0;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!param_cmp(av[i], "--bench"))
			opt->benchmark = 1;
		else if (!set_method(opt, av[i], &method_set))
			return (-1);
		i++;
	}
	return (i);
}
