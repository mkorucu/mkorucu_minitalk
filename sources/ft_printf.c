/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:29:45 by mkorucu           #+#    #+#             */
/*   Updated: 2022/07/06 16:26:07 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	rt_len;

	rt_len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (*s)
		rt_len += ft_putchar(*s++);
	return (rt_len);
}

int	ft_putunbr(unsigned int num)
{
	int	rt_len;

	rt_len = 0;
	if (num > 9)
		rt_len += ft_putnbr(num / 10);
	rt_len += ft_putchar((num % 10) + '0');
	return (rt_len);
}

int	ft_detector(va_list ag, const char c)
{
	int		rt_len;

	rt_len = 0;
	if (c == 'c')
		rt_len += ft_putchar(va_arg(ag, int));
	else if (c == 's')
		rt_len += ft_putstr(va_arg(ag, char *));
	else if (c == 'p')
		rt_len += ft_hex(va_arg(ag, unsigned long), "0123456789abcdef", 1);
	else if (c == 'd')
		rt_len += ft_putnbr(va_arg(ag, int));
	else if (c == 'i')
		rt_len += ft_putnbr(va_arg(ag, int));
	else if (c == 'u')
		rt_len += ft_putunbr(va_arg(ag, unsigned int));
	else if (c == 'x')
		rt_len += ft_hex(va_arg(ag, unsigned int), "0123456789abcdef", 0);
	else if (c == 'X')
		rt_len += ft_hex(va_arg(ag, unsigned int), "0123456789ABCDEF", 0);
	else if (c == '%')
		rt_len += write(1, "%", 1);
	return (rt_len);
}

int	ft_printf(const char *str, ...)
{
	int		rt_len;
	va_list	ag;

	rt_len = 0;
	va_start(ag, str);
	while (*str)
	{
		if (*str == '%')
			rt_len += ft_detector(ag, *(++str));
		else
			rt_len += ft_putchar(*str);
		str++;
	}
	va_end (ag);
	return (rt_len);
}
