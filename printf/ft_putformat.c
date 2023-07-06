/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:07:25 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/04 12:12:01 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putformat(va_list args, char const *format)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == "c")
				c = c + ft_putchar(va_arg(args, char));
			else if (format[i + 1] == "s")
				c = c + ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == "i" || format[i + 1] == "d" || format[i + 1] == "x"
				|| format[i + 1] == "X" || format[i + 1] == "u")
				c = c + number_type(format[i + 1], args);
			else if (format[i + 1] == "p")
				c = c + ft_address(va_arg(args, void *));
			else if (format[i + 1] == "%")
				c = c + ft_putchar(format[i + 1]);
			else
				c = c + ft_putchar(format[i]);
		}
		else
			c = c + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (c);
}