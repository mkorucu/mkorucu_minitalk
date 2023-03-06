/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:33:31 by mkorucu           #+#    #+#             */
/*   Updated: 2022/08/29 18:55:11 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putnbr(int num);
int	ft_printf(const char *str, ...);
int	ft_detector(va_list ag, const char c);
int	ft_hex(unsigned long num, char *base, int checker);
int	ft_putunbr(unsigned int num);
int	ft_putstr(char *s);
int	ft_putchar(int c);
int	ft_atoi(const char *str);

#endif
