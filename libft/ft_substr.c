/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:41:54 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/06 16:53:09 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	c;

	if (ft_strlen(s) <= start)
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sb = (char *)malloc((len + 1) * (sizeof(char)));
	if (!sb)
		return (NULL);
	c = 0;
	while (ft_strlen(s) > start && s[start + c] && c < len)
	{
		sb[c] = ((char *)s)[start + c];
		c++;
	}
	sb[c] = '\0';
	return (sb);
}
