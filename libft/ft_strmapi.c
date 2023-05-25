/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:43:23 by codespace         #+#    #+#             */
/*   Updated: 2023/05/25 11:03:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int     i;
	char	*d;

    i = 0;
	if (s == NULL)
		return (NULL);
    d = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[i] != '\0')
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	return (d);
}
