/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:46:12 by sarferna          #+#    #+#             */
/*   Updated: 2023/06/12 15:04:07 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	*lst = new;
}
// en la struct de new senyalo como next a la propia lst, entonces asigno
// a la direccion del primer puntero de lst la direccion de new.
// en el caso de no existir lst, entonces igualamos el primer puntero de lst
// a la direccion de new. 
