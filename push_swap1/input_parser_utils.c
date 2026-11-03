/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:41:11 by kasen             #+#    #+#             */
/*   Updated: 2026/11/03 15:41:14 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	get_sign(const char **cursor)
{
	int	sign;

	sign = 1;
	if (**cursor == '-' || **cursor == '+')
	{
		if (**cursor == '-')
			sign = -1;
		(*cursor)++;
	}
	return (sign);
}

static int	read_digits(const char **cursor, long long limit,
		long long *number)
{
	long long	digit;

	if (**cursor < '0' || **cursor > '9')
		return (0);
	while (**cursor >= '0' && **cursor <= '9')
	{
		digit = **cursor - '0';
		if (*number > (limit - digit) / 10)
			return (0);
		*number = *number * 10 + digit;
		(*cursor)++;
	}
	if (**cursor && !is_space(**cursor))
		return (0);
	return (1);
}

void	skip_spaces(const char **cursor)
{
	while (is_space(**cursor))
		(*cursor)++;
}

int	parse_number(const char **cursor, int *value)
{
	long long	number;
	long long	limit;
	int			sign;

	sign = get_sign(cursor);
	limit = 2147483647LL;
	if (sign == -1)
		limit = 2147483648LL;
	number = 0;
	if (!read_digits(cursor, limit, &number))
		return (0);
	*value = (int)(number * sign);
	return (1);
}
