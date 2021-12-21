/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:24:09 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/20 17:35:37 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_receive;

void	receiver(int signum, siginfo_t *siginfo, void *noUse)
{
	static int	i;
	static char	c;

	g_receive = siginfo->si_pid;
	noUse += 0;
	if (signum == SIGUSR1)
		c = c | (1 << i);
	else if (signum == SIGUSR2)
		c = c | (0 << i);
	i++;
	if (i < 8)
		return ;
	if (c == 0)
		ft_putchar('\n');
	write(1, &c, 1);
	c = 0;
	i = 0;
}

int	main(void)
{
	struct sigaction	sa;

	g_receive = 0;
	sa.sa_sigaction = &receiver;
	sa.sa_flags = SA_SIGINFO;
	printdecimal(getpid());
	ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		if (g_receive != 0)
		{
			kill(g_receive, SIGUSR1);
			g_receive = 0;
		}
		pause();
	}
}
