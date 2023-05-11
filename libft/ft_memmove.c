/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:52:49 by codespace         #+#    #+#             */
/*   Updated: 2023/05/11 12:44:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *memmove(void *dst, const void *src, size_t n)
{
   size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
    // necesito hacer que no haya overlop entre los arrays
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}