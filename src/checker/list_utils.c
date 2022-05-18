/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:26:58 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 12:31:02 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_dlist	*lstnew(int content)
{
	t_dlist	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = list;
	list->prev = list;
	return (list);
}

void	lstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
}

void	*lstclear(t_dlist *cur, t_dlist *start)
{
	if (!cur)
		return (NULL);
	if (cur->next != start)
		lstclear(cur->next, start);
	free(cur);
	return (NULL);
}

void	lstdel(t_dlist **cur)
{
	t_dlist	*next;
	t_dlist	*prev;

	if ((*cur)->next == (*cur))
	{
		*cur = NULL;
	}
	else
	{
		prev = (*cur)->prev;
		next = (*cur)->next;
		prev->next = next;
		next->prev = prev;
		*cur = next;
	}
}
