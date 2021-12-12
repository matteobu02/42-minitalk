/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:09:45 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/03 13:10:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	ft_printf("%d characters sent.\n", ft_strlen(s));
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(300);
	}
}

void	get_signals(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		received++;
	else
	{
		ft_printf("%d characters received.\n", received);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
		ft_error("Invalid number of arguments.\n");
	pid = ft_atoi(av[1]);
	if (pid == -1)
		ft_error("Invalid PID.\n");
	sa.sa_handler = get_signals;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	send_signals(pid, av[2]);
	while (1)
		pause();
	return (0);
}
