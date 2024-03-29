/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:48:16 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/16 13:12:14 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && needle[j] && i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (j < ft_strlen(needle))
		return (NULL);
	return (((char *)haystack) + (i - j));
}
