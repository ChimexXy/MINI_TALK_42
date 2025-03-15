/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:26:33 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/15 08:48:14 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recive_bit(int signal, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static int				pid = 0;
	static unsigned char	tmp = 0;

	(void)context;
	(void)info;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit = 0;
		tmp = 0;
	}
	bit++;
	tmp = tmp | (signal == SIGUSR1);
	if (bit == 8)
	{
		write(1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
	else
		tmp = tmp << 1;
}

int main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	put_nbr(pid);
	write(1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = recive_bit;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
		pause();
}
