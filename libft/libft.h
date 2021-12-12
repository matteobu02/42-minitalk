/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:05:26 by mbucci            #+#    #+#             */
/*   Updated: 2021/11/30 13:49:43 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_atoi(char *s);
void	ft_error(char *s);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);

/*** FT_PRINTF ***/

int		ft_printf(const char *str, ...);
void	ft_case_c(va_list argp);
void	ft_case_s(va_list argp, int *ptr);
void	ft_case_p(va_list argp, int *ptr);
void	ft_case_di(va_list argp, int *ptr);
void	ft_case_u(va_list argp, int *ptr);
void	ft_case_x(va_list argp, int c, int *ptr);
int		ft_count_chars(unsigned long n);
void	ft_utohexa(unsigned long n, int *ptr, int ca);

#endif
