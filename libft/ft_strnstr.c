/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:48:16 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/16 18:55:26 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && ft_strlen(haystack) != 0
		&& ft_strlen(haystack) >= ft_strlen(needle))
	{
		while (haystack[i] == needle[c] && c < ft_strlen(needle) && i < len)
		{
			c++;
			i++;
		}
		if (c == ft_strlen(needle))
			return (((char *)haystack) + (i - c));
		else
		{
			i = i - c + 1;
			c = 0;
		}
	}
	return (0);
}
