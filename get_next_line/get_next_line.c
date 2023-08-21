/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:22 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/21 14:15:11 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_free(char **buf)
{
	free (*buf);
	*buf = NULL;
	return (NULL);
}

char	*ft_rest_read(char *rest_buf)
{
	int		i;
	int		j;
	char	*new_rest;

	i = 0;
	j = 0;
	while (rest_buf[i] && rest_buf[i] != '\n')
		i++;
	if (rest_buf[i] == '\0')
	{
		free(rest_buf);
		return (NULL);
	}
	new_rest = (char *)malloc((ft_strlen(rest_buf) - i + 1) * sizeof(char));
	if (!new_rest)
		return (NULL);
	i++;
	while (rest_buf[i])
		new_rest[j++] = rest_buf[i++];
	new_rest[j] = '\0';
	free (rest_buf);
	return (new_rest);
}

char	*ft_define_line(char *rest_buf)
{
	int		i;
	char	*line;

	i = 0;
	while (rest_buf[i] && rest_buf[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (rest_buf[i] && rest_buf[i] != '\n')
	{
		line[i] = rest_buf[i];
		i++;
	}
	if (rest_buf[i] == '\n')
	{
		line[i] = rest_buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *rest_buf)
{
	char	*buf;
	ssize_t	rv;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rv = 1;
	while (rv > 0 && !ft_strchr(rest_buf, '\n'))
	{
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv > 0)
		{
			buf[rv] = '\0';
			rest_buf = ft_strjoin(rest_buf, buf);
		}
	}
	free (buf);
	if (rv == -1)
		return (ft_free(&rest_buf));
	if ((rest_buf && ft_strlen(rest_buf) == 0) && rv == 0)
		return (ft_free(&rest_buf));
	return (rest_buf);
}

char	*get_next_line(int fd)
{
	static char	*rest_buf;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!rest_buf)
	{
		rest_buf = (char *)malloc(1 * sizeof(char));
		if (!rest_buf)
			return (NULL);
		rest_buf[0] = '\0';
	}
	rest_buf = ft_read(fd, rest_buf);
	if (!rest_buf)
		return (ft_free(&rest_buf));
	line = ft_define_line(rest_buf);
	rest_buf = ft_rest_read(rest_buf);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*a;

// 	fd = open ("documento.txt", O_RDONLY);
// 	a = get_next_line(fd);
// 	printf("%s", a);
// 	free (a);
// 	close(fd);
// 	return (0);
// }
