/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:58:16 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/17 13:24:36 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	size_t	r;
	size_t	c;

	i = 0;
	r = 0;
	c = 0;
	if (n == 0)
		return (0);
	while ((((char *)s1)[i] == ((char *)s2)[i]) && i < n)
	{
		if (i == n - 1)
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}