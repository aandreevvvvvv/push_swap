/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:35:22 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 16:47:31 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_dlist *lst)
{
	if (lst)
		ft_swap((int *)&(lst->content), (int *)&(lst->next->content));
}

void	push(t_dlist **from, t_dlist **to)
{
	t_dlist	*cur;

	if (!*from)
		return ;
	cur = *from;
	lstdel(from);
	cur->next = cur;
	cur->prev = cur;
	lstadd_front(to, cur);
}

int	rotate(t_dlist **lst)
{
	if (!*lst)
		return (0);
	*lst = (*lst)->next;
	return (1);
}

int	reverse_rotate(t_dlist **lst)
{
	if (!*lst)
		return (0);
	*lst = (*lst)->prev;
	return (1);
}
