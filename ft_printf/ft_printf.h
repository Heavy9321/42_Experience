/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kasen <kasen@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/12 15:28:47 by kasen            #+#    #+#              */
/*   Updated: 2026/09/16 15:43:32 by kasen           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_hub(const char c, va_list *varg);
int	ft_putchar(char s);
int	ft_putnbr(long nb);
int	ft_putnbr_hex(long unsigned int nb, char *hex_base);
int	ft_putpntr(void *ptr);
int	ft_putstr(char *s1);

#endif
