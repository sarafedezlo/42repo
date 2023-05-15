/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:24:07 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/15 15:58:32 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;

	r = (char *)s;
	while (*r != '\0')
	{
		if (*r == (unsigned char)c)
			return (r);
		r++;
	}
	if ((unsigned char)c == '\0')
		return (r);
	return (0);
}
