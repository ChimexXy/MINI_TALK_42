/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:23:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/15 07:37:16 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(unsigned char c, int pid)
{
	int bit;

	bit = 7;
	while(bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int pid;

	i = 0;
	if (ac != 3)
	{
		write(1, "Invalid argument\n", 17);
		return (1);
	}
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
