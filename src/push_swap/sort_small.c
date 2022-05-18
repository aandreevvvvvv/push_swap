/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:28 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/26 19:01:59 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_dlist *lst, char c)
{
	if (lst->content > lst->next->content)
		swap(lst, c);
}

static void	sort_3(t_dlist **lst, char c)
{
	if ((*lst)->content == 0 && (*lst)->next->content == 2)
	{
		swap(*lst, c);
		rotate(lst, c);
	}
	else if ((*lst)->content == 1)
	{
		if ((*lst)->next->content == 0)
			swap(*lst, c);
		else
			reverse_rotate(lst, c);
	}
	else if ((*lst)->content == 2)
	{
		if ((*lst)->next->content == 0)
			rotate(lst, c);
		else
		{
			swap(*lst, c);
			reverse_rotate(lst, c);
		}
	}
}

static void	sort_4(t_dlist **a, t_dlist **b)
{
	move(a, find(*a, 3, 3), 'a');
	push(a, b, 'b');
	sort_3(a, 'a');
	push(b, a, 'a');
	rotate(a, 'a');
}

static void	sort_5(t_dlist **a, t_dlist **b)
{
	move(a, find(*a, 4, 4), 'a');
	push(a, b, 'b');
	move(a, find(*a, 3, 3), 'a');
	push(a, b, 'b');
	sort_3(a, 'a');
	push(b, a, 'a');
	rotate(a, 'a');
	push(b, a, 'a');
	rotate(a, 'a');
}

void	sort_small(t_dlist **a, t_dlist **b, size_t n)
{
	if (n == 2)
		sort_2(*a, 'a');
	else if (n == 3)
		sort_3(a, 'a');
	else if (n == 4)
		sort_4(a, b);
	else
		sort_5(a, b);
}
