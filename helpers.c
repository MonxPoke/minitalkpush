/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:28:46 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/20 17:22:39 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	printdecimal(int n)
{
	unsigned int	newvar;

	newvar = n;
	if (n < 0)
	{
		newvar = -n;
		ft_putchar('-');
	}
	if (newvar <= 9)
		ft_putchar(newvar + 48);
	else
	{
		printdecimal(newvar / 10);
		ft_putchar(newvar % 10 + 48);
	}
}

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	res;
	unsigned int			i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		if (res >= 9223372036854775807 && sign == -1)
			return (0);
	}
	return (res * sign);
}
