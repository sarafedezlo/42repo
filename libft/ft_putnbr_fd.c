/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:47:22 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/20 14:13:02 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	array_n[11];
	int		i;

	i = 0;
	if (n == 0)
		write (fd, "0", 1);
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	if (n < 0 && n > -2147483648)
	{
		n = n * -1;
		write (fd, "-", 1);
	}
	while (n > 0 && n <= 2147483647)
	{
		array_n[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	array_n[i] = '\0';
	while (i-- > 0)
		write (fd, &array_n[i], 1);
}
