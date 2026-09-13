/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:28:46 by kasen             #+#    #+#             */
/*   Updated: 2026/09/12 20:39:57 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hub(const char c, va_list varg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(varg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(varg, char *)));
	if (c == 'p')
		return (ft_putpntr(va_arg(varg, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(varg, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(varg, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hex(va_arg(varg, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_hex(va_arg(varg, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
}
