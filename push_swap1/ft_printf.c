/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaktas <onaktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:37:20 by onaktas           #+#    #+#             */
/*   Updated: 2026/11/03 15:37:24 by onaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_print_chr(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_print_str(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_print_num(long n, int fd)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_print_chr('-', fd);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_print_num(n / 10, fd);
	ft_print_chr((n % 10) + '0', fd);
	return (++count);
}

static int	format_check(const char *str, va_list args, int fd)
{
	int	total;

	total = 0;
	if (*str == 's')
		total += ft_print_str(va_arg(args, char *), fd);
	else if (*str == 'd')
		total += ft_print_num(va_arg(args, int), fd);
	else if (*str == '%')
		total += ft_print_str("%", fd);
	return (total);
}

int	ft_printf(const char *str, int fd, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, fd);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			total += format_check(&str[i + 1], args, fd);
			i += 2;
		}
		else
			total += ft_print_chr(str[i++], fd);
	}
	va_end(args);
	return (total);
}
