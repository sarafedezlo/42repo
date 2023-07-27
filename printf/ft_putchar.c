/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:55:29 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/25 16:57:07 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char k, int c)
{
	if (write (1, &k, 1) == -1)
		c = -1;
	else
		c += 1;
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
