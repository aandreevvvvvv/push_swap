/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:57:54 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/29 19:46:35 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

static int	check_sorted(int *arr, size_t n, char *op)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		++i;
	}
	if (op != NULL)
	{
		free(op);
		free(arr);
		write(1, "KO\n", 3);
		return (1);
	}
	return (0);
}

int	process_operations(t_dlist **a, t_dlist **b, char *op)
{
	while (op)
	{
		if (!do_operation(a, b, op))
		{
			free(op);
			lstclear(*a, *a);
			lstclear(*b, *b);
			return (0);
		}
		free(op);
		op = get_next_line(0);
	}
	return (1);
}

int	sort(int *arr, size_t n)
{
	t_dlist	*a;
	t_dlist	*b;
	char	*op;

	op = get_next_line(0);
	if (check_sorted(arr, n, op))
		return (1);
	a = arr_to_list(arr, n);
	if (!a)
		return (0);
	b = NULL;
	if (!process_operations(&a, &b, op))
		return (0);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lstclear(a, a);
	lstclear(b, b);
	return (1);
}
