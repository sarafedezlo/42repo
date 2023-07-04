/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_primero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:50:04 by sarferna          #+#    #+#             */
/*   Updated: 2023/07/04 11:54:57 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main() {
    char *str;
    char **pstr;
    
    str = "Hello, World!";
    pstr = &str;
    
    printf("%p%%%\n", (void *)str);
    printf("%s\n", *pstr);
    
    return 0;
}