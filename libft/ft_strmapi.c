/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:55:21 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/26 13:58:55 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*d;

	i = 0;
	if (s == NULL)
		return (NULL);
	d = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[i] != '\0' && d != NULL)
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	return (d);
}
