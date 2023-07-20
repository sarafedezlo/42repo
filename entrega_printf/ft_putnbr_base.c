/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:39:38 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/20 18:41:46 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char k, int c)
{
	if (write (1, &k, 1) == -1)
		c = -1;
	else
		c = c + 1;
	return (c);
}

int	ft_putstr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", c));
	while (s[i] && c != -1)
	{
		c = ft_putchar(s[i], c);
		i++;
	}
	return (c);
}

int	ft_putnbr_base_x(long int nbr, int b, int c)
{
	long int	n;
	char		*base;

	n = nbr;
	if (b == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n / 16 > 0)
		ft_putnbr_base_x((n / 16), b, c);
	if (c == -1)
		return (c);
	c = ft_putchar(base[n % 16], c);
	return (c);
}

int	ft_putnbr_base_dir(unsigned long long nbr, int c)
{
	unsigned long long	n;

	n = nbr;
	if (!nbr)
		return (ft_putchar('0', c));
	if (n > 15)
	{
		ft_putnbr_base_dir((n / 16), c);
		if (c == -1)
			return (c);
		c = ft_putchar("0123456789abcdef"[n % 16], c);
	}
	else
		c = ft_putchar("0123456789abcdef"[n], c);
	return (c);
}

int	ft_putnbr_base_10(unsigned int nbr, int c)
{
	unsigned int	n;

	n = nbr;
	if (n / 10 > 0)
	{
		ft_putnbr_base_dir((n / 10), c);
		if (c == -1)
			return (c);
		c = ft_putchar("0123456789"[n % 10], c);
	}
	else
		c = ft_putchar("0123456789"[n], c);
	return (c);
}
