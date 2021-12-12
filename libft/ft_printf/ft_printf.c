/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:21:27 by mbucci            #+#    #+#             */
/*   Updated: 2021/11/30 13:51:18 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_manage(int c, va_list argp, int *ptr)
{
	if (c == 'c')
		ft_case_c(argp);
	else if (c == 's')
		ft_case_s(argp, ptr);
	else if (c == 'p')
		ft_case_p(argp, ptr);
	else if (c == 'd' || c == 'i')
		ft_case_di(argp, ptr);
	else if (c == 'u')
		ft_case_u(argp, ptr);
	else if (c == 'x' || c == 'X')
		ft_case_x(argp, c, ptr);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	if (c == 'c' || c == '%')
		*ptr += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	argp;
	int		str_size;

	str_size = 0;
	va_start(argp, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str_size += 1;
		}
		else
		{
			str++;
			ft_manage(*str, argp, &str_size);
		}
		str++;
	}
	va_end(argp);
	return (str_size);
}
