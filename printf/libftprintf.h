/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:48:18 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/03 13:09:06 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
int 	ft_putchar(char c);
int 	ft_putstr(char *s);
int 	ft_putnbr_base(unsigned long long nbr, char *base);

#endif
