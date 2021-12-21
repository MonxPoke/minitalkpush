/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:23:54 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/20 17:26:43 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	isreceived(int signum)
{
	signum += 0;
	ft_putstr("signal is received\n");
}

void	sender(int bit, int pid)
{
	if (bit == 1)
	{
		kill(pid, SIGUSR1);
	}
	else if (bit == 0)
	{
		kill(pid, SIGUSR2);
	}
}

void	client(int serverpid, char *str)
{
	int	bit;
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			bit = (*str >> i) & 1;
			i++;
			sender(bit, serverpid);
			signal(SIGUSR1, &isreceived);
			usleep(100);
		}
		str++;
	}
	i = 0;
	while (i++ < 8)
	{
		sender(0, serverpid);
		signal(SIGUSR1, &isreceived);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3 && ft_atoi(argv[1]) != 0)
		client(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("Error, Syntax is : client [PID] [String]");
}
