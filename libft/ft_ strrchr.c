/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:02:22 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/08 19:17:07 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s) - 1;
    while (i >= 0)
    {
        if (s[i] == c)
            return (s[i]);
        i--;
    }
    return (NULL);
}