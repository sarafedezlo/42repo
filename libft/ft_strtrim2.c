/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:27:32 by codespace         #+#    #+#             */
/*   Updated: 2023/05/31 19:41:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//identificar cuando no es caracter de set por el principio.
int	strchr_counter_f(char const *s1, char const *set)
{
	int r;
	int	i;
	int c;
	int	t;

	r = 0;
	c = 0;
	t = 0;
	while (s1[r] != '\0')
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (set[i] == s1[r])
				c++;
			i++;
		}
		if (t == c)
			return (c);
		t = c;
		r++;
	}
	return (0);
}
//identificar cuando no es caracter de set por el final.
int	strchr_counter_e(char const *s1, char const *set)
{
	int r;
	int	i;
	int c;
	int	t;

	r = ft_strlen(s1);
	c = 0;
	t = 0;
	while (r > 0)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (set[i] == s1[r])
				c++;
			i++;
		}
		if (t == c)
			return (c);
		t = c;
		r--;
	}
	return (0);
}
//hacer un malloc con la len de s1-caracteres prinicpio-caracteresfinal+1.
char	*ft_strtrim(char const *s1, char const *set)
{
	int		f;
	int		e;
	char	*m;
	
	if (!s1 || !set)
		return (NULL);
	f = strchr_counter_f(s1, set);
	e = strchr_counter_e(s1, set);
	m = malloc(ft_strlen(s1) - f - e + 1, sizeof(char));
	if (!m)
		return (NULL);
	cpy_str(s1, m, f);
	return(m);
}
//rellenar de s1, a partir de caracterespricipio hasta final de malloc.
void	cpy_str(char const *s1, char *m, int f)
{
	int	i;
	int	r;

	i = f - 1;
	while (r <= ft_strlen(m))
	{
		m[r] = s1[i];
		i++;
		r++;
	}
}