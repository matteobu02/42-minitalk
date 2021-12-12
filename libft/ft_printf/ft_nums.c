/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:01:37 by mbucci            #+#    #+#             */
/*   Updated: 2021/11/30 13:51:04 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_num(unsigned int n, int *ptr)
{
	if (n > 0)
	{
		ft_print_num(n / 10, ptr);
		ft_putchar_fd(n % 10 + 48, 1);
		*ptr += 1;
	}
}

void	ft_case_di(va_list argp, int *ptr)
{
	int	i;

	i = va_arg(argp, int);
	if (i < 0)
	{
		ft_putchar_fd('-', 1);
		i = -i;
		*ptr += 1;
	}
	else if (i == 0)
	{
		ft_putchar_fd(48, 1);
		*ptr += 1;
		return ;
	}
	ft_print_num((unsigned int)i, ptr);
}

void	ft_case_u(va_list argp, int *ptr)
{
	int	i;

	i = va_arg(argp, unsigned int);
	if (i == 0)
	{
		ft_putchar_fd(48, 1);
		*ptr += 1;
		return ;
	}
	ft_print_num(i, ptr);
}
