/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:31:32 by sarferna          #+#    #+#             */
/*   Updated: 2023/09/06 17:00:30 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

//INPUTS:
//Inputs en forma de argumentos:
//	Revisar que sean numeros
//	Revisar que no hayan repetidos
//	Contar num de inputs
//Inputs en forma de string:
//	Split
//	Revisar que sean numeros
//	Revisar que no hayan repetidos
//	Contar num de inputs

//FUNCIONES DEL PUSH SWAP
//Swap
//Push
//Rotate
//Reverse rotate
//especial para 4 inputs
//especial para 5 inputs

static int	aux_words(char const *s, char c)
{
	int				words;
	unsigned long	i;

	i = 0;
	words = 0;
	if (s[i] && s[i] != c)
		words++;
	while (i < ft_strlen(s))
	{
		if (i != 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static void	aux_free(char **listword, int x)
{
	while (--x >= 0)
		free(listword[x]);
	free(listword);
}

static char	**aux_lenword(char const *s, char c, char **listword, int i)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	while ((size_t)i < ft_strlen(s))
	{
		if (s[i] != c && (s[i + 1] == c || (size_t)(i + 1) == ft_strlen(s)))
		{
			listword[x] = ft_substr(s, (i - j), j + 1);
			if (!listword[x])
			{
				aux_free(listword, x);
				return (NULL);
			}
			j = 0;
			x++;
			i++;
		}
		if (s[i] != c)
			j++;
		i++;
	}
	return (listword);
}

char	**ft_split(char const *str, char separator)
{
	int		i;
	char	**listword;

	i = 0;
	if (!str)
		return (NULL);
	listword = (char **)malloc ((aux_words(s, separator) + 1) * sizeof(char *));
	if (!listword)
		return (NULL);
	listword[aux_words(str, separator)] = NULL;
	return (aux_lenword(str, separator, listword, i));
}
// aplicar atoi en la listword; si falla return error. 

int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	long	result;

	flag = 0;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		result = -result;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return (result);
}
// Revision de errores post atoi para ver si es un resultado valido o no.
//escribirlo por el canal 2.
if (num == 0 && strcmp(str, "0") != 0)
	return ("Error");

// int main (void)
// {
// 	char *str = "999a9";

// 	printf("%i", ft_atoi(str));
// 	return (0);
// }