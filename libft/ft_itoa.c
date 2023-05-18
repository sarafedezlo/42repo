/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:30:15 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/18 17:55:20 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int		r;
	int					i;
	char				*a;

	r = (unsigned int)n;
	i = 1;
	while (r != 0)
	{
		r /= 10;
		i++;
	}
	if (n < 0)
	{
		i = i + 1;
		r = -1;
	}
	a = malloc(i * sizeof(char));
	if (!a)
		return (NULL);
	a[i] = '\0';
	while (i-- >= 0)
	{
		a[i] = n % 10;
		n /= 10;
		if (r == -1)
			a[0] = '-';
	}
	return (a);
}
