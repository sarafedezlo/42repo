/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:56:44 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/06 16:43:55 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	same_char(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (base[j] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

static int	sign_char(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_strlen(char *base)
{
	int	c;

	c = 0;
	while (base[c] != '\0')
		c++;
	return (c);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long	n;
	int					i;

	n = nbr;
	i = 0;
	if ((ft_strlen(base) != 0 && ft_strlen(base) != 1)
		|| (same_char(base) != 0) || (sign_char(base) != 0))
	{
		if (n / ft_strlen(base) > 0)
			ft_putnbr_base((n / ft_strlen(base)), base);
		write(1, &base[n % ft_strlen(base)], 1);
		i++;
	}
	return (i);
}
