/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:21:53 by sarferna          #+#    #+#             */
/*   Updated: 2023/09/04 17:29:52 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;
void	ft_algoritm(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lst_swap(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));

#endif