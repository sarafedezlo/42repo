/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:19:32 by sarferna          #+#    #+#             */
/*   Updated: 2023/09/04 18:57:31 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
		del(lst->content);
	free(lst);
}

void	ft_lst_swap(t_list *lst)
{
	int		r;
	t_list	*temp;

	r = lst->content;
	temp = lst->next;
	lst->content = temp->content;
	temp->content = r;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}


void	ft_algoritm(t_list *lst, void (*del)(void *))
{
	int	n;

	n = ft_lstsize(lst_a);
	while (flag_ordenacion_a == 0 && ft_lstsize != n)
	{
		//comparacion de primero con segundo y ultimo
		while ((lst_a->content > (lst_a->next)->content ||
				lst_a->content > ft_lstlast(lst_a)->content) ||
			(lst_b->content < (lst_b->next)->content ||
				lst_b->content < ft_lstlast(lst_b)->content))
		{
			//comparar el primero con el segundo
			if (lst_a->content > (lst_a->next)->content &&
				lst_b->content < (lst_b->next)->content)
			{
				ft_lst_swap(lst_a);
				ft_lst_swap(lst_b);
				ft_putstr("ss");
			}
			else if (lst_a->content > (lst_a->next)->content)
			{
				ft_lst_swap(lst_a);
				ft_putstr("sa");
			}
			else if (lst_b->content < (lst_b->next)->content)
			{
				ft_lst_swap(lst_b);
				ft_putstr("sb");
			}
			//comparar el primero con el ultimo
			if (lst_a->content > ft_lstlast(lst_a)->content &&
				lst_b->content < ft_lstlast(lst_b)->content)
			{
				ft_lstadd_front(lst_a, ft_lstlast(lst_a));
				ft_lstdelone(ft_lstlast(lst_a), del);
				ft_lstadd_front(lst_b, ft_lstlast(lst_b));
				ft_lstdelone(ft_lstlast(lst_b), del);
				ft_putstr("rrr");
			}
			else if (lst_a->content > ft_lstlast(lst_a)->content)
			{
				ft_lstadd_front(lst_a, ft_lstlast(lst_a));
				ft_lstdelone(ft_lstlast(lst_a), del);
				ft_putstr("rra");
			}
			else if (lst_b->content < ft_lstlast(lst_b)->content)
			{
				ft_lstadd_front(lst_b, ft_lstlast(lst_b));
				ft_lstdelone(ft_lstlast(lst_b), del);
				ft_putstr("rrb");
			}
		}
		//comparacion con los primeros de los dos stacks
		if ((!lst_b && flag_ordenacion_a == 0) ||
			(flag_ordenacion_b == 1 && ft_lstsize(lst_a) > 3))
		{
			if (!lst_b)
			{
				lst_b = ft_lstnew(lst_a->content);//me falta declararlo
				ft_lstdelone(lst_a, del);
				ft_putstr("pb");
			}
			else
			{
				ft_lstadd_front(lst_b, lst_a);
				ft_lstdelone(lst_a, del);
				ft_putstr("pb");
			}
		}
		
		while (flag_ordenacion_b == 0 && ((lst_a->content < (lst_a->next)->content &&
				lst_a->content < ft_lstlast(lst_a)->content) &&
				(lst_b->content > (lst_b->next)->content &&
				lst_b->content > ft_lstlast(lst_b)->content)))
		{
			ft_lstadd_front(lst_a, lst_b);
			ft_lstdelone(lst_b, del);
			ft_putstr("pa");
		}
		while ((flag_ordenacion_a == 1 && flag_ordenacion_b == 1) &&
			(lst_a->content > (lst_b->content)))//suponemos que si deja de existir b se para
		{
			ft_lstadd_front(lst_a, lst_b);
			ft_lstdelone(lst_b, del);
			ft_putstr("pa");
		}
	}
	//en la flag de ordenacion, si solo tiene un elemento, dar por ordenado.
}
