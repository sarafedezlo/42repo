/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:26 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/06 16:17:59 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			r++;
		i++;
	}
	return (r);
}


char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		pi;

	i = 0;
	j = 0;
	pi = 0;
	if (!s)
		return (NULL);
	a = (char **)malloc(count_word(s, c) + 1 * sizeof(char *));
	if (!a)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			pi = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') && pi != 0)
		{
			a[j] = ft_substr(s, pi, i - pi);
			if (!a[j])
			{
				while (j > 0)
					free(a[--j]);
				free(a);
				return (NULL);
			}
			j++;
			pi = 0;
		}
		i++;
	}
	a[j] = NULL;
	return (a);
}

// int	main(void)
// {
//  	char *s = "    hola      que   tal    wena    teta     ";

// 	char	**y;
// 	int	i;

// 	i = 0;
// 	y = ft_split(s, ' ');
// 	while (y[i])
// 	{
// 		printf("%s\n", y[i]);
// 		i++;
// 	}
// }