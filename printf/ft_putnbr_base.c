/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:56:44 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/10 18:20:52 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_strlen(char *base)
{
	int	c;

	c = 0;
	while (base[c] != '\0')
		c++;
	return (c);
}

static int	count_num(unsigned long long nbr, char *base)
{
	unsigned long long	n;
	int					i;

	n = nbr;
	i = 0;
	if ((ft_strlen(base) != 0 && ft_strlen(base) != 1))
	{
		while (n > 0)
		{
			i++;
			n = n / ft_strlen(base);
		}
	}
	return (i);
}

int	ft_putnbr_base(unsigned long long nbr, char *base, int c)
{
	unsigned long long	n;
	unsigned long long	s;

	n = nbr;
	s = nbr;
	if (n / ft_strlen(base) > 0)
		ft_putnbr_base((n / ft_strlen(base)), base, c);
	if (write(1, &base[n % ft_strlen(base)], 1) == -1)
		return (-1);
	return (c + count_num(s, base));
}
