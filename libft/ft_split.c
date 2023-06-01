/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:26 by sarferna          #+#    #+#             */
/*   Updated: 2023/05/26 13:42:47 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//cuento las palabras que tiene la string inicial.
int	word_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			counter++;
		i++;
	}
	return (counter);
}

// cuento los caracteres de una palabra, desde la posicion de sr actualizada
// generando un calloc con ese volumen, en su posicion.
void	char_counter_gnrt(char const *sr, char c, char **b, int bi)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (sr[i] == c)
		i++;
	while (sr[i])
	{
		if (sr[i] != c)
			t++;
		if (sr[i] != c && sr[i + 1] == c)
			b[bi] = (char *)ft_calloc(t + 1, sizeof(char));
		i++;
	}
}

//cada vez que abanzo en b en el nivel alto hago esto "len" veces.
//copio a cada string la parte correspondiente de sr y devuelvo la direccion 
// de sr para poder retomarlo en "i" en la siguiente iteracion
char	*char_cpy_direc(char *sr, char c, char **b, int bi)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (sr[i] == c)
		i++;
	while (sr[i])
	{
		if (sr[i] != c)
		{
			b[bi][t] = sr[i];
			t++;
		}
		if (sr[i] != c && sr[i + 1] == c)
			return (&sr[i]);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**b;
	char	*sr;
	int		bi;

	bi = 0;
	if (!s)
		return (NULL);
	sr = ft_strdup(s);
	b = ft_calloc(word_counter(s, c) + 1, sizeof(char));
	while (bi <= word_counter(s, c))
	{
		char_counter_gnrt(sr, c, b, bi);
		sr = char_cpy_direc(sr, c, b, bi);
		if (!b[bi])
		{
			while (bi-- >= 0)
				free (b[bi]);
			free (b);
			return (NULL);
		}
		bi++;
	}
	return (b);
}
