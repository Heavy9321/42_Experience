/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:28:45 by kasen             #+#    #+#             */
/*   Updated: 2026/09/14 17:28:14 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	return (write(1, &s, 1));
}

int	ft_putnbr(long nb)
{
	long	num;
	int		len;
	int		temp;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb *= -1;
		len += 1;
	}
	num = nb % 10 + '0';
	if (nb >= 10)
	{
		temp = ft_putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &num, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hex(unsigned int nb, char *hex_base)
{
	int	len;
	int	temp;

	len = 0;
	if (nb >= 16)
	{
		temp = ft_putnbr_hex(nb / 16, hex_base);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &hex_base[nb % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putpntr(void *ptr)
{
	int	len;
	int	temp;

	len = 0;
	temp = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "(nil)", 2) == -1)
		return (-1);
	len = len + 2;
	temp = ft_putnbr_hex((unsigned long) ptr, "0123456789abcdef");
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}

int	ft_putstr(char *s1)
{
	int	len;

	if (!s1)
		if (write(1, "(null)", 6))
		len = 0;
	while (*s1)
	{
		if (write(1, s1, 1) == -1)
			return (-1);
		len++;
		s1++;
	}
	return (len);
}
