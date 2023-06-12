/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:30:15 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/12 11:44:46 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num_sign_null(int r)
{
	int	i;

	i = 0;
	if (r == 0)
		i++;
	if (r < 0)
	{
		r = r * -1;
		i++;
	}
	while (r > 0)
	{
		r = r / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		r;
	int		i;
	char	*a;

	r = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = count_num_sign_null(r);
	a = ft_calloc(i + 1, sizeof(char));
	if (!a)
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		n *= -1;
	}
	if (n == 0)
		a[0] = '0';
	while (n > 0)
	{
		i--;
		a[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (a);
}
