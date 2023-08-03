/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:50 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/03 16:37:03 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *rest_buf);
char	*ft_define_line(char *rest_buf);
char	*ft_rest_read(char *rest_buf);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *rest_buf, char *buf);

#endif
