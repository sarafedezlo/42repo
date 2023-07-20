/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:57 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/20 17:56:15 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	number_type(char const format_char, va_list args, int c)
{
	int	n;

	if (format_char == 'i' || format_char == 'd')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			if (n == -2147483648)
			{
				c = ft_putstr("-2147483648", c);
				return (c);
			}
			c = ft_putchar('-', c);
			n *= -1;
		}
		c = ft_putnbr_base_10(n, c);
	}
	if (format_char == 'u')
		c = ft_putnbr_base_10(va_arg(args, unsigned int), c);
	else if (format_char == 'X')
		c = ft_putnbr_base_x(va_arg(args, long int), 0, c);
	else 
		c = ft_putnbr_base_x(va_arg(args, long int), 1, c);
	return (c);
}

static int	ft_putformat(va_list args, char const *format, int i, int c)
{
	if (format[i] == 'c')
		c = ft_putchar(va_arg(args, int), c);
	else if (format[i] == 's')
		c = ft_putstr(va_arg(args, char *), c);
	else if (format[i] == 'i' || format[i] == 'd' || format[i] == 'x'
		|| format[i] == 'X' || format[i] == 'u')
		c = number_type(format[i], args, c);
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
	while (format[i] && c != -1)
	{
		if (format[i] == '%')
		{
			i++;
			c = ft_putformat(args, format, i, c);
		}
		else
			c = ft_putchar(format[i], c);
		i++;
	}
	return (c);
}
