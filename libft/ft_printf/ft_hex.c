/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:21:44 by mbucci            #+#    #+#             */
/*   Updated: 2021/11/30 13:50:50 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_write_hexa(unsigned long n, char *str, int *ptr, int ca)
{
	if (n % 16 > 9)
		ft_putchar_fd(str[n % 10] + ca, 1);
	else
		ft_putchar_fd(n % 16 + 48, 1);
	*ptr += 1;
}

void	ft_print_hexa(unsigned long n, char *str, int *ptr, int ca)
{
	if (n / 16 == 0)
		ft_write_hexa(n % 16, str, ptr, ca);
	else
	{
		ft_print_hexa(n / 16, str, ptr, ca);
		ft_write_hexa(n % 16, str, ptr, ca);
	}
}

void	ft_case_p(va_list argp, int *ptr)
{
	unsigned long	i;

	i = (unsigned long)va_arg(argp, void *);
	ft_putstr_fd("0x", 1);
	ft_print_hexa(i, "abcdef", ptr, 0);
	*ptr += 2;
}

void	ft_case_x(va_list argp, int c, int *ptr)
{
	unsigned int	i;
	int				ca;

	if (c == 'X')
		ca = 0;
	else
		ca = 32;
	i = va_arg(argp, unsigned int);
	ft_print_hexa(i, "ABCDEF", ptr, ca);
}
