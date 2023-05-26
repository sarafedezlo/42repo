/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:30:15 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/23 12:56:31 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num_sign_null(int r)
{
	int	i;

	i = 0;
	if (r == -2147483648)
		return (12);
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

char	*min_int_char(char *a)
{
	a[0] = '-';
	a[1] = '2';
	a[2] = '1';
	a[3] = '4';
	a[4] = '7';
	a[5] = '4';
	a[6] = '8';
	a[7] = '3';
	a[8] = '6';
	a[9] = '4';
	a[10] = '8';
	return (a);
}

char	*ft_itoa(int n)
{
	int		r;
	int		i;
	char	*a;

	r = n;
	i = count_num_sign_null(r);
	a = ft_calloc(i + 1, 1);
	if (!a)
		return (NULL);
	if (n == -2147483648)
		return (min_int_char(a));
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
