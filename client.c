/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:23:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/12 02:42:43 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bits(char c, int pid)
{
	int bit;

	bit = 7;
	while(bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		usleep(130);
	}
}

int main(int ac, char **av)
{
	int	i;
	int pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3 || !av[2])
		ft_printf("Invalid argument\n");
	if (pid == -1)
		return (0);
	while (av[2][i])
	{
		send_bits(av[2][i], pid);
		i++;
	}
	send_bits(av[2][i], pid);
}
