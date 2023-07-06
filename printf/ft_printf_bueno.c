/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bueno.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:45:51 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/06 11:20:01 by sarferna         ###   ########.fr       */
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
