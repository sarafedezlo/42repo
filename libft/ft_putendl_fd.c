/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:20:46 by codespace         #+#    #+#             */
/*   Updated: 2023/05/25 12:25:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putendl_fd(char *s, int fd)
{
        int i;

    i = 0;
    if (!*s)
        return ((void)NULL);
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i++;
    }
    write(fd, &s[i], 1);
    write(fd, "\n", 1);
}
