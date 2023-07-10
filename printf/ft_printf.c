/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:45:51 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/10 18:16:19 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = ft_putformat(args, format);
	va_end(args);
	return (i);
}

int	main()
{
	char	*str;
	int		l;

	str = "Hello, World!";
	l = -234567;
	printf("---%i\n", printf("---%s\n", str));
	printf("+++%i\n", ft_printf("+++%s\n", str));
	printf("---%i\n", printf("---%s---%d\n", str, l));
	printf("+++%i\n", ft_printf("+++%s+++%d\n", str, l));
	return (0);
}
