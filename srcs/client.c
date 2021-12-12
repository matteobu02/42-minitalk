/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:20 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/03 13:11:08 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *s)
{
	int	shift;
	int	i;

	i = -1;
	while (s[++i])
	{
		shift = -1;
		while (++shift < 8)
		{
			if (s[i] & (0x80 >> shift))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		ft_error("Invalid number of arguments.\n");
	pid = ft_atoi(av[1]);
	if (pid == -1)
		ft_error("Invalid PID.\n");
	send_signals(pid, av[2]);
	return (0);
}
