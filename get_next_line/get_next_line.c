/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:22 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/26 19:21:49 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	num_buf;
	char	buf[42];

	num_buf = 42;
	read(fd, buf, num_buf);
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
