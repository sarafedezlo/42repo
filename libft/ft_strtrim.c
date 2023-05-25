/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:18 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/25 10:02:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	size_t	c;
	size_t	len;

	i = 0;
	c = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, ((int)s1) + i) == 0)
			c++;
		i++;
	}
	s = ft_calloc(c + 1, sizeof(char));
	i = 0;
	while (!s)
	{
		if (ft_strchr(set, ((int)s1) + i) == 0)
		{
			s = ((char *)s1)[i];
			s++;
		}
		i++;
	}
	return (s);
}
