/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:11:21 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/03 13:11:51 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sigusrs(int sig, siginfo_t *info, void *context)
{
	static pid_t	cli_pid = 0;
	static int		i = 0;
	static char		c = 0;

	(void)context;
	if (!cli_pid)
		cli_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(cli_pid, SIGUSR2);
			cli_pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
		kill(cli_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID : %d\n", getpid());
	sa.sa_sigaction = handle_sigusrs;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
