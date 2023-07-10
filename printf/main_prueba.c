/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:50:04 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/10 15:00:03 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*int main()
{
	char *str;
	char *pstr;
	str = "";
	pstr[20] = &str;
	
	printf("%p\n", str);
	printf("0x%s\n", pstr);
	return (0);
}*/

int	main()
{
	char	*str;

	str = "Hello, World!";
	printf("%s\n", str);
	ft_printf("%s\n", str);
	printf("%i\n", ft_printf("%s\n", str));
	return (0);
}
