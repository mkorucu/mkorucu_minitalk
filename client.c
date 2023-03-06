/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:17 by mkorucu           #+#    #+#             */
/*   Updated: 2022/08/31 11:19:45 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_sender(int pid, int c)
{
	unsigned char	b;
	int				bin;

	bin = 128;
	b = c;
	while (bin > 0)
	{
		if (b / bin)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		b = b % bin;
		bin /= 2;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3 && argv[2])
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
			ft_sender(pid, argv[2][i++]);
	}
	else if (argc != 3)
		ft_printf("wrong number of argument");
	return (0);
}
