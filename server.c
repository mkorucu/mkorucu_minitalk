/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:25 by mkorucu           #+#    #+#             */
/*   Updated: 2023/03/06 16:17:39 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiver(int signal)
{
	static int	i = 128;
	static char	c = 0;

	if (signal == SIGUSR1)
		signal = 1;
	else if (signal == SIGUSR2)
		signal = 0;
	c += (i * signal);
	if (i == 1)
	{
		i = 256;
		ft_printf("%c", c);
		c = 0;
	}
	i /= 2;
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, receiver);
	signal(SIGUSR2, receiver);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		pause();
}
