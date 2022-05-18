/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:57:54 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/28 17:05:16 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static t_dlist	*free_lst_arr(t_dlist **lst_arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(lst_arr[i++]);
	free(lst_arr);
	return (NULL);
}

static t_dlist	*arr_to_list(int *arr, size_t n)
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
		if (!lst_arr[i])
			return (free_lst_arr(lst_arr, i));
		++i;
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
	return (lst);
}

static int	is_sorted(int *arr, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		++i;
	}
	free (arr);
	return (1);
}

int	sort(int *arr, size_t n)
{
	t_dlist	*a;
	t_dlist	*b;

	if (is_sorted(arr, n))
		return (1);
	a = arr_to_list(arr, n);
	free(arr);
	if (!a)
		return (0);
	b = NULL;
	if (n > 5)
	{
		push_chunk(&a, &b, n);
		sort_chunk(&a, &b, n);
	}
	else
		sort_small(&a, &b, n);
	lstclear(a, a);
	lstclear(b, b);
	return (1);
}
