/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:05:54 by mkorucu           #+#    #+#             */
/*   Updated: 2022/08/31 11:10:01 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	total;

	total = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		total += write(1, "-", 1);
		num *= -1;
	}
	if (num > 9)
		total += ft_putnbr(num / 10);
	total += ft_putchar((num % 10) + '0');
	return (total);
}

int	ft_hex(unsigned long num, char *base, int checker)
{
	int	total;

	total = 0;
	if (checker)
		total += write(1, "0x", 2);
	if (num / 16 != 0)
		total += ft_hex(num / 16, base, 0);
	total += write(1, &base[num % 16], 1);
	return (total);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		number = (number * 10) + (str[i] - 48) * sign;
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
		i++;
	}
	return (number);
}
