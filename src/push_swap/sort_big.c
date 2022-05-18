/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:34:39 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/26 20:19:24 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	find_forward(t_dlist *lst, unsigned int min, unsigned int max)
{
	int		i;
	t_dlist	*cur;

	if (lst->content >= min && lst->content <= max)
		return (0);
	i = 1;
	cur = lst->next;
	while (cur != lst)
	{
		if (cur->content >= min && cur->content <= max)
			return (i);
		++i;
		cur = cur->next;
	}
	return (INT_MAX);
}

int	find(t_dlist *lst, unsigned int min, unsigned int max)
{
	int		i;
	t_dlist	*cur_f;
	t_dlist	*cur_b;

	if (lst->content >= min && lst->content <= max)
		return (0);
	i = 1;
	cur_f = lst->next;
	cur_b = lst->prev;
	while (cur_f != lst && cur_b != lst)
	{
		if (cur_f->content >= min && cur_f->content <= max)
			return (i);
		if (cur_b->content >= min && cur_b->content <= max)
			return (-i);
		++i;
		cur_f = cur_f->next;
		cur_b = cur_b->prev;
	}
	return (INT_MAX);
}

void	move(t_dlist **lst, int moves, char c)
{
	size_t	i;

	i = 0;
	if (moves < 0)
	{
		moves *= -1;
		while (i < (size_t)moves)
		{
			reverse_rotate(lst, c);
			++i;
		}
	}
	else
	{
		while (i < (size_t)moves)
		{
			rotate(lst, c);
			++i;
		}
	}
}

void	push_chunk(t_dlist **a, t_dlist **b, size_t n)
{
	size_t			i;
	unsigned int	offset;

	i = 0;
	while (i < n)
	{
		offset = 3 * (n - i) / 80 + 12;
		move(a, find_forward(*a, 0, i + offset), 'a');
		push(a, b, 'b');
		if ((*b)->content < i)
			rotate(b, 'b');
		++i;
	}
}

void	sort_chunk(t_dlist **a, t_dlist **b, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		move(b, find(*b, n - i - 1, n - i - 1), 'b');
		push(b, a, 'a');
		++i;
	}
}
