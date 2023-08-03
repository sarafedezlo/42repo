/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:22 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/03 16:48:57 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rest_read(char *rest_buf)
{
	int		i;
	int		j;
	char	*new_rest;

	i = 0;
	j = 0;
	while (rest_buf[i] && rest_buf[i] != '\n')
		i++;
	if (!rest_buf[i])
	{
		free (rest_buf);
		return (NULL);
	}
	new_rest = (char *)malloc((ft_strlen(rest_buf) - i + 1) * sizeof(char));
	if (!new_rest)
		return (NULL);
	new_rest[ft_strlen(new_rest)] = '\0';
	while (new_rest[j])
		new_rest[j++] = rest_buf[++i];
	free (rest_buf);
	return (new_rest);
}

char	*ft_define_line(char *rest_buf)
{
	int	i;
	char	*line;

	i = 0;
	if (!rest_buf)
		return (NULL);
	while (rest_buf[i] && rest_buf[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	line[ft_strlen(line)] = '\0';
	i = 0;
	while (line[i])
		line[i] = rest_buf[i++];
	return (line);
}

char	*ft_read(int fd, char *rest_buf)
{
	char	*buf;
	int		rv;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return(NULL);
	rv = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	if (rv > 0)
		rest_buf = ft_strjoin(rest_buf, buf);
	free (buf);
	if (!rest_buf || rv <= 0)
			return (NULL);
	return (rest_buf);
}

char	*get_next_line(int fd)
{
	static char	*rest_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest_buf = ft_read(fd, rest_buf);
	line = ft_define_line(rest_buf);
	rest_buf = ft_rest_read(rest_buf);
	return (line);
}

/*int	main(void)
{
	int	fd;

	fd = open("",O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error \n");
		return (0);
	}
	get_next_line(fd);
	close(fd);
	return (0);
}*/

