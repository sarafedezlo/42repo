/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:07:25 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/10 18:21:07 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	number_type(char const format_char, va_list args)
{
	int	n;
	int	c;

	c = 0;
	if (format_char == 'i' || format_char == 'd' || format_char == 'u')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			if (format_char != 'u')
				c = ft_putchar('-');
			n *= -1;
		}
		return (ft_putnbr_base((unsigned long long) n, "0123456789", c));
	}
	else if (format_char == 'X')
	{
		n = va_arg(args, unsigned long long);
		return (ft_putnbr_base(n, "0123456789ABCDEF", 0));
	}
	n = va_arg(args, unsigned long long);
	return (ft_putnbr_base(n, "0123456789abcdef", 0));
}

static int	format_types(char const *format, int i, va_list args)
{
	if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd'
		|| format[i + 1] == 'x' || format[i + 1] == 'X'
		|| format[i + 1] == 'u')
		return (number_type(format[i + 1], args));
	else if (format[i + 1] == 'p')
		return (ft_putnbr_base((unsigned long long)va_arg(args, void *),
				"0123456789ABCDEF", 0));
	else if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else
		return (ft_putchar(format[i + 1]));
}

int	ft_putformat(va_list args, char const *format)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			c += format_types(format, i, args);
			i++;
		}
		else
			c += ft_putchar(format[i]);
		i++;
	}
	return (c);
}
