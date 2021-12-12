/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:15:06 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/03 13:12:02 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (signum == SIGUSR1)
		c ^= (0x80 >> bits);
	else if (signum == SIGUSR2)
		c |= (0x80 >> bits);
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
	return (0);
}
