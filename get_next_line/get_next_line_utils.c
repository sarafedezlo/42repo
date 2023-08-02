/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:27 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/26 16:09:32 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sr;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	sr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sr)
		return (NULL);
	while (s1[i])
	{
		sr[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		sr[i + c] = s2[c];
		c++;
	}
	sr[i + c] = '\0';
	return (sr);
}

