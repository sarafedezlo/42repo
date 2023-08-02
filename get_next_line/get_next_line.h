/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:37:50 by sarferna          #+#    #+#             */
/*   Updated: 2023/08/02 19:34:14 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif
