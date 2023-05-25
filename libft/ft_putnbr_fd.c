/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:18:06 by codespace         #+#    #+#             */
/*   Updated: 2023/05/25 13:21:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char    *a;
    int     i;
    int     c;
    
    a = ft_itoa(n);
    if (!*a)
        return ((void)NULL);
    ft_putstr_fd(a, fd);
}