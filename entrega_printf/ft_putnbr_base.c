/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:39:38 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/25 16:56:47 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base_x(unsigned int nbr, int b, int c)
{
	unsigned int	n;
	char			*base;

	n = nbr;
	if (b == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n / 16 > 0)
		c = ft_putnbr_base_x((n / 16), b, c);
	if (c == -1)
		return (c);
	c = ft_putchar(base[n % 16], c);
	return (c);
}

int	ft_putnbr_base_dir(unsigned long long nbr, int c)
{
	unsigned long long	n;

	n = nbr;
	if (n / 16 > 0)
		c = ft_putnbr_base_dir((n / 16), c);
	if (c == -1)
		return (c);
	c = ft_putchar("0123456789abcdef"[n % 16], c);
	return (c);
}

int	ft_putnbr(int nbr, int c)
{
	int	n;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			c = ft_putstr("-2147483648", c);
			return (c);
		}
		c = ft_putchar('-', c);
		nbr *= -1;
	}
	n = nbr;
	if ((n / 10) > 0)
		c = ft_putnbr((n / 10), c);
	if (c == -1)
		return (c);
	c = ft_putchar((n % 10) + '0', c);
	return (c);
}

int	ft_putnbr_unsigned(unsigned int nbr, int c)
{
	unsigned int	n;

	n = nbr;
	if ((n / 10) > 0)
		c = ft_putnbr_unsigned((n / 10), c);
	if (c == -1)
		return (c);
	c = ft_putchar((n % 10) + '0', c);
	return (c);
}
