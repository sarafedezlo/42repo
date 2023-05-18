/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:18 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/18 17:09:27 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*a;
	const char	*b;
	const char	*c;

	a = malloc(ft_strlen(ft_strnstr(s1, set, ft_strlen(set))));
	b = malloc(ft_strlen(ft_strnstr(a, set, ft_strlen(set))));
	if (b != a)
		c = malloc(ft_strlen(s1) - ft_strlen(a) - ft_strlen(set) - \
			- ft_strlen(b) - ft_strlen(set));
	else
		c = malloc(ft_strlen(s1) - ft_strlen(a) - ft_strlen(set));

}
