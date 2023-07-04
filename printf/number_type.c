/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:07:41 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/04 12:46:57 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int number_type(char const format_char, va_list args)
{
    int c;
    int n;

    c = 0;
    if (format_char == "i")
    {
        n = va_arg(args, int);
        if (n < 0)
        {
            c = c + ft_putchar("-");
            n *= -1;
        }
        c = ft_putnbr_base((unsigned long long) n, "0123456789");
    }
    else if (format_char == "d")
    {
        
    }
    else if (format_char == "X")
    {
        n = va_arg(args, unsigned long long);
        c = ft_putnbr_base( n, "0123456789ABCDEF");
    }
    else if (format_char == "x")
    {
        n = va_arg(args, unsigned long long);
        c = ft_putnbr_base(n, "0123456789abcdef");
    }
    else
    {
        n = va_arg(args, unsigned long long);
        if (n < 0)
            n *= -1;
        c = ft_putnbr_base( n, "0123456789");
    }
    return (c);
}