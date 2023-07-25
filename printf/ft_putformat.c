/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:07:25 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/25 11:58:23 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	number_type(char const format_char, va_list args)
{
	int	n;
	int	c;

	c = 0;
	if (format_char == 'i' || format_char == 'd')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			if (n == -2147483648)
				return (ft_putstr("-2147483648"));
			c = ft_putchar('-');
			n *= -1;
		}
		if (c == -1)
			return (c);
		return (ft_putnbr_base(n, "0123456789") + c);
	}
	if (format_char == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (format_char == 'X')
		return (ft_putnbr_base(va_arg(args, long int),
				"0123456789ABCDEF"));
	return (ft_putnbr_base(va_arg(args, long int), "0123456789abcdef"));
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
	{
		ft_putstr("0x");
		return (ft_putnbr_base_d(va_arg(args, unsigned long),
				"0123456789abcdef"));
	}
	else
		return (ft_putchar('%'));
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
			if (format[i + 1] == '%' || format[i + 1] == 'p'
				|| format[i + 1] == 'u' || format[i + 1] == 'X'
				|| format[i + 1] == 'x' || format[i + 1] == 'd'
				|| format[i + 1] == 'i' || format[i + 1] == 's'
				|| format[i + 1] == 'c')
			{
				c += format_types(format, i, args);
				i++;
			}
			else
				c = -1;
		}
		else
			c += ft_putchar(format[i]);
		i++;
	}
	return (c);
}
