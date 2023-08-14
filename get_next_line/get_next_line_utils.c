/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:27 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/14 18:43:06 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

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

	i = -1;
	c = -1;
	sr = (char *)malloc((ft_strlen(rest_buf) + ft_strlen(buf) + 1) \
		* sizeof(char));
	if (!sr)
		return (NULL);
	while (rest_buf[++i])
		sr[i] = rest_buf[i];
	while (buf[++c])
		sr[i + c] = buf[c];
	sr[ft_strlen(rest_buf) + ft_strlen(buf)] = '\0';
	free (rest_buf);
	return (sr);
}
