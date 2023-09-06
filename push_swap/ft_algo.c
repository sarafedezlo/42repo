/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarferna <sarferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:12:29 by sarferna          #+#    #+#             */
/*   Updated: 2023/09/06 17:30:35 by sarferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void ft_pa(t_list *lst_a, t_list *lst_b, void (*del)(void *))
{
	ft_lstadd_front(lst_a, lst_b);
	ft_lstdelone(lst_b, del);
	ft_putstr("pa\n");
}

void ft_final_pa(t_list *lst_a, t_list *lst_b, void (*del)(void *))
{
	ft_lstadd_front(lst_a, lst_b);
	ft_lstdelone(lst_b, del);
	ft_putstr("pa\n");
}

void ft_new_pb(t_list *lst_a, t_list *lst_b, void (*del)(void *))
{
	lst_b = ft_lstnew(lst_a->content);//me falta declararlo
	ft_lstdelone(lst_a, del);
	ft_putstr("pb\n");
}

void	ft_pb(t_list *lst_a, t_list *lst_b, void (*del)(void *))
{
	ft_lstadd_front(lst_b, lst_a);
	ft_lstdelone(lst_a, del);
	ft_putstr("pb\n");
}

void	ft_rrr_rra_rrb(t_list *lst_a, t_list *lst_b, void (*del)(void *))
{
	if (lst_a->content > ft_lstlast(lst_a)->content &&
		lst_b->content < ft_lstlast(lst_b)->content)
	{
		ft_lstadd_front(lst_a, ft_lstlast(lst_a));
		ft_lstdelone(ft_lstlast(lst_a), del);
		ft_lstadd_front(lst_b, ft_lstlast(lst_b));
		ft_lstdelone(ft_lstlast(lst_b), del);
		ft_putstr("rrr\n");
	}
	else if (lst_a->content > ft_lstlast(lst_a)->content)
	{
		ft_lstadd_front(lst_a, ft_lstlast(lst_a));
		ft_lstdelone(ft_lstlast(lst_a), del);
		ft_putstr("rra\n");
	}
	else if (lst_b->content < ft_lstlast(lst_b)->content)
	{
		ft_lstadd_front(lst_b, ft_lstlast(lst_b));
		ft_lstdelone(ft_lstlast(lst_b), del);
		ft_putstr("rrb\n");
	}
}

void	ft_ss_sa_sb(t_list *lst_a, t_list *lst_b)
{
	if (lst_a->content > (lst_a->next)->content &&
		lst_b->content < (lst_b->next)->content)
	{
		ft_lst_swap(lst_a);
		ft_lst_swap(lst_b);
		ft_putstr("ss\n");
	}
	else if (lst_a->content > (lst_a->next)->content)
	{
		ft_lst_swap(lst_a);
		ft_putstr("sa\n");
	}
	else if (lst_b->content < (lst_b->next)->content)
	{
		ft_lst_swap(lst_b);
		ft_putstr("sb\n");
	}
}

void	ft_frst_scd_lst(t_list *lst_a, t_list *lst_b, void (*del)(void *))
{
	int	n;

	n = ft_lstsize(lst_a);
	while (flag_ordenacion_a == 0 && ft_lstsize != n)
	{
		while ((lst_a->content > (lst_a->next)->content ||
				lst_a->content > ft_lstlast(lst_a)->content) ||
			(lst_b->content < (lst_b->next)->content ||
				lst_b->content < ft_lstlast(lst_b)->content))
		{
			ft_ss_sa_sb(lst_a, lst_b);
			ft_rrr_rra_rrb(lst_a, lst_b, del);
		}
		if ((!lst_b && flag_ordenacion_a == 0) ||
			(flag_ordenacion_b == 1 && ft_lstsize(lst_a) > 3))
		{
			if (!lst_b)
				ft_new_pb(lst_a, lst_b, del);
			else
				ft_pb(lst_a, lst_b, del);
		}
		while (flag_ordenacion_b == 0 && ((lst_a->content < (lst_a->next)->content
					&& lst_a->content < ft_lstlast(lst_a)->content) &&
				(lst_b->content > (lst_b->next)->content &&
					lst_b->content > ft_lstlast(lst_b)->content)))
			ft_pa(lst_a, lst_b, del);
		while ((flag_ordenacion_a == 1 && flag_ordenacion_b == 1) &&
				(lst_a->content > (lst_b->content)))//suponemos que si deja de existir b se para
			ft_final_pa(lst_a, lst_b, del);
		//en la flag de ordenacion, si solo tiene un elemento, dar por ordenado.
	}
}

// void	ft_ss(t_list *lst_a, t_list *lst_b)
// {
// 	ft_lst_swap(lst_a);
// 	ft_lst_swap(lst_b);
// 	ft_putstr("ss");
// }

// void	ft_sa(t_list *lst_a, t_list *lst_b)
// {
// 	ft_lst_swap(lst_a);
// 	ft_putstr("sa");
// }

// void	ft_sa(t_list *lst_a, t_list *lst_b)
// {
// 	ft_lst_swap(lst_b);
// 	ft_putstr("sb");
// }
