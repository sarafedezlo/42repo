/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:26 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/07 17:05:19 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	r;

	i = 1;
	r = 0;

	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		r++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			r++;
		i++;
	}
	return (r);
}


char	**free_array(char **a, int j)
{
	while (j > 0)
		free(a[--j]);
	free(a);
	return (NULL);
}

char	**allocate_string(char **a, char *s, char c)
{
	int		i;
	int		j;
	int		pi;

	i = 0;
	j = 0;
	pi = 0;
	while (s[i])
	{
		if (s[i] != c)
			pi++;
		i++;
		if ((s[i] == c || s[i] == '\0') && pi != 0)
		{
			a[j] = ft_substr(s, i - pi, pi);
			if (!a[j])
				return (free_array(a, j));
			j++;
			pi = 0;
		}
	}
	a[j] = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;

	if (!s)
		return (NULL);
	a = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	return (allocate_string(a, (char *)s, c));
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