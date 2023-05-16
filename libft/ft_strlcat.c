/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:22:51 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/16 17:43:57 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstr;

	i = 0;
	j = 0;
	dstr = ft_strlen((const char *)dest);
	if (dstsize != 0 && dstsize > ft_strlen((const char *)dest))
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0' && (i + j) < (dstsize - 1))
		{
			dest[i + j] = ((char *)src)[j];
			j++;
		}
		dest[i + j] = '\0';
		if (src[j] == '\0')
			return (ft_strlen((const char *)dest));
		else
			return (dstr + ft_strlen(src));
	}
	return (ft_strlen(src) + dstsize);
}
