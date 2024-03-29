/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:14:39 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/25 16:53:41 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_writeformat(va_list args, char const *format);
int	ft_putchar(char k, int c);
int	ft_putstr(char *s, int c);
int	ft_putnbr_base_x(unsigned int nbr, int b, int c);
int	ft_putnbr_base_dir(unsigned long long nbr, int c);
int	ft_putnbr(int nbr, int c);
int	ft_putnbr_unsigned(unsigned int nbr, int c);

#endif
