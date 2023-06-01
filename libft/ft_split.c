/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:26 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/01 17:43:50 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	if (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			r++;
		i++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		pi;

	i = 0;
	if (!s)
		return (NULL);
	*a = malloc(count_word(s, c) + 1);
	if (!*a)
		return (NULL);
	while (s[i])
	{
		if (((char *)s)[i] != c && s[i - 1] == c || i = 0 && s[i] != c)
			pi = i;
		if ((s[i] == c && s[i + 1] != c) && pi != 0)
		{
			a[j] = ft_substr(*s, pi - 1, i - pi);
			if (!a[j])
			{
				while (j > 0)
					free (a[--j]);
				free (a);
				return (NULL);
			}
			j++;
			pi = 0;
		}
		i++
	}
	return (a);
}
