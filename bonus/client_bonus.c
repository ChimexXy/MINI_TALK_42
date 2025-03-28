/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:25:23 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/27 02:38:34 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(unsigned char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit--;
	}
}

void	mes_recive(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message Recive Successfully :) \n", 32);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		write(1, "Invalid argument\n", 17);
		return (1);
	}
	signal(SIGUSR1, mes_recive);
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		write(1, "Invalid PID\n", 12);
		return (1);
	}
	while (av[2][i])
	{
		send_bits(av[2][i], pid);
		i++;
	}
	send_bits(av[2][i], pid);
	return (0);
}
