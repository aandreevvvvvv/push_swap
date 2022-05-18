/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:35:22 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/26 19:21:36 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *lst, char c)
{
	ft_swap((int *)&(lst->content), (int *)&(lst->next->content));
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(t_dlist **from, t_dlist **to, char c)
{
	t_dlist	*cur;

	cur = *from;
	lstdel(from);
	cur->next = cur;
	cur->prev = cur;
	lstadd_front(to, cur);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_dlist **lst, char c)
{
	*lst = (*lst)->next;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_dlist **lst, char c)
{
	*lst = (*lst)->prev;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
