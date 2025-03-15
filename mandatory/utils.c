/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:04:21 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/15 08:27:30 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void put_nbr(int n)
{
	if (n > 9)
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int ft_atoi(char *str)
{
	int	i;
	int sig;
	int res;

	i = 0;
	sig = 1;
	res = 0;
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return(-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res * sig);
}
