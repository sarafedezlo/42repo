/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:54:14 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/01 16:11:47 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchr(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*f;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (checkchr(set, s1[i]) == 1)
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (checkchr(set, s1[len -1]) == 1)
		len--;
	f = malloc(len - i + 1);
	if (!f)
		return (NULL);
	while (len - i)
		f[j++] = s1[i++];
	f[j] = '\0';
	return (f);
}
