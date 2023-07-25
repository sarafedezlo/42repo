/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:57 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/25 16:53:42 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putformat(va_list args, char const *format, int i, int c)
{
	if (format[i] == 'c')
		c = ft_putchar(va_arg(args, int), c);
	else if (format[i] == 's')
		c = ft_putstr(va_arg(args, char *), c);
	else if (format[i] == 'i' || format[i] == 'd')
		c = ft_putnbr(va_arg(args, int), c);
	else if (format[i] == 'u')
		c = ft_putnbr_unsigned(va_arg(args, unsigned int), c);
	else if (format[i] == 'X')
		c = ft_putnbr_base_x(va_arg(args, unsigned int), 0, c);
	else if (format[i] == 'x')
		c = ft_putnbr_base_x(va_arg(args, unsigned int), 1, c);
	else if (format[i] == 'p')
	{
		c = ft_putstr("0x", c);
		c = ft_putnbr_base_dir((unsigned long long)va_arg(args, void *), c);
	}
	else if (format[i] == '%')
		c = ft_putchar('%', c);
	else
		c = -1;
	return (c);
}

int	ft_writeformat(va_list args, char const *format)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c = ft_putformat(args, format, i, c);
			if (c == -1)
				return (-1);
		}
		else
		{
			c = ft_putchar(format[i], c);
			if (c == -1)
				return (-1);
		}
		i++;
	}
	return (c);
}
