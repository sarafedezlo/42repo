/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:27 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/03 16:47:14 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *rest_buf, char *buf)
{
	char	*sr;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!rest_buf)
	{
		rest_buf = malloc(1 * sizeof(char));
		if (!rest_buf)
			return (NULL);
		rest_buf[0] = '\0';
	}
	sr = malloc((ft_strlen(rest_buf) + ft_strlen(buf) + 1) * sizeof(char));
	if (!sr)
		return (NULL);
	while (rest_buf[i])
		sr[i] = rest_buf[i++];
	while (buf[c])
		sr[i + c] = buf[c++];
	sr[i + c] = '\0';
	return (sr);
}
