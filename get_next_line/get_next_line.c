/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:22 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/02 19:41:12 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	main(void)
{
	int	fd;

	fd = open("/Users/sarferna/Desktop/42repo/get_next_line/documento",
			O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error \n");
		return (0);
	}
	get_next_line(fd);
	close(fd);
	return (0);
}
