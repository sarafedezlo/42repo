/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:45:51 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/21 16:17:09 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int	ft_printf(char const *format, ...)
{
	va_list	args;
	char *s;
	int i;
	int j = 3;

	va_start(args, format);
	s = va_arg(args, char*);
	i = printf("%s%d%s%b\n", s, j, s);
	puts(va_arg(args, char*));
	puts(va_arg(args, char*));
	puts(s);
	printf("%d", i);
	return (0);
}

/*format: hola %s, com estas;
while (format)
if format[i] == %
{
	detect(format[i + 1])
}

if format[i] == c
	printchar(va_arg(args, char))
else if format[i] == s
	printstring(va_arg(args, char*))
else if format[i] == d || format[i] == i
	printnum(va_arg(args, int))
else (si es cualquier cosa que no este en la lista %y%lmnb)
	write(format[i])
	*/

int	main()
{
	char *format;
	char *txt1;
	char *txt2;
	char *txt3;

	format = "nada";
	txt1 = "text1";
	txt2 = "text2";
	txt3 = "text3";
	ft_printf(format, txt1, txt2, txt3);
	return (0);
}