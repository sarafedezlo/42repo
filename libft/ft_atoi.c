/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:39:10 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/17 15:29:21 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	m;

	i = 0;
	n = 0;
	m = 1;
	while ((str[i] == '-' || str[i] == '+' || (str[i] >= 9 && str[i] <= 13)
			|| str[i] == 32))
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (ft_isdigit((int)str[i + 1]) == 0)
				return (0);
			if (str[i] == '-')
				m = -1;
		}
		i++;
	}
	while (ft_isdigit((int)str[i]) == 1)
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * m);
}
