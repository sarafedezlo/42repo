/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:52:08 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/15 17:14:17 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
