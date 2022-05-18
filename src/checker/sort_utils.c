/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:03:42 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/29 19:21:19 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_dlist	*free_lst_arr(t_dlist **lst_arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(lst_arr[i++]);
	free(lst_arr);
	return (NULL);
}

t_dlist	*arr_to_list(int *arr, size_t n)
{
	t_dlist	*lst;
	t_dlist	**lst_arr;
	size_t	i;

	lst_arr = malloc(sizeof(t_dlist *) * n);
	if (!lst_arr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		lst_arr[i] = lstnew(arr[i]);
		if (!lst_arr[i++])
			return (free_lst_arr(lst_arr, i - 1));
	}
	i = 0;
	while (i < n)
	{
		lst_arr[i]->next = lst_arr[(i + 1) % n];
		lst_arr[i]->prev = lst_arr[(n + i - 1) % n];
		++i;
	}
	lst = lst_arr[0];
	free(lst_arr);
	free(arr);
	return (lst);
}

int	is_sorted(t_dlist *lst)
{
	t_dlist	*cur;
	t_dlist	*prev;

	prev = lst;
	cur = lst->next;
	while (cur != lst)
	{
		if (prev->content > cur->content)
			return (0);
		prev = cur;
		cur = cur->next;
	}
	return (1);
}

static int	do_operation2(t_dlist **a, t_dlist **b, char *op)
{
	if (ft_streq(op, "ra\n"))
		return (rotate(a));
	if (ft_streq(op, "rb\n"))
		return (rotate(b));
	if (ft_streq(op, "rr\n"))
		return (rotate(a) && rotate(b));
	if (ft_streq(op, "rra\n"))
		return (reverse_rotate(a));
	if (ft_streq(op, "rrb\n"))
		return (reverse_rotate(b));
	if (ft_streq(op, "rrr\n"))
		return (reverse_rotate(a) && reverse_rotate(b));
	return (0);
}

int	do_operation(t_dlist **a, t_dlist **b, char *op)
{
	if (ft_streq(op, "sa\n"))
		swap(*a);
	else if (ft_streq(op, "sb\n"))
		swap(*b);
	else if (ft_streq(op, "ss\n"))
	{
		swap(*a);
		swap(*b);
	}
	else if (ft_streq(op, "pa\n"))
		push(b, a);
	else if (ft_streq(op, "pb\n"))
		push(a, b);
	else
		return (do_operation2(a, b, op));
	return (1);
}
