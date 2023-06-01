/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:18 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/26 18:22:13 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	same_char(const char *s, char c)
{
	char	*r;

	r = (char *)s;
	while (*r != '\0')
	{
		if (*r == c)
			return (1);
		r++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

void	num_find(char const *set, char const *s1, int i, size_t c)
{
	int	len;

	len = ft_strlen(s1);
	while ((same_char(set, (int)s1[i]) == 0) && s1[i] != '\0')
		i++;
	while (same_char(set, (int)s1[len]) == 0)
	{
		c++;
		len--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		d;
	size_t	c;

	i = 0;
	d = 0;
	c = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	num_find(set, s1, i, c);
	s = ft_calloc(ft_strlen(s1) - i - c + 1, sizeof(char));
	if (!s)
		return (NULL);
	while ((size_t)d < ft_strlen(s))
	{
		s[d] = s1[i];
		d++;
		i++;
	}
	return (s);
}
