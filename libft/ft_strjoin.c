/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:20:40 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/18 15:37:02 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
