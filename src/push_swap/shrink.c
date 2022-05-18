/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:17:38 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/29 18:38:28 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_qsort(int *arr, size_t n)
{
	int		pivot;
	size_t	l;
	size_t	r;

	pivot = arr[n / 2];
	l = 0;
	r = n - 1;
	while (l <= r)
	{
		while (arr[l] < pivot)
			++l;
		while (arr[r] > pivot)
			--r;
		if (l <= r)
			ft_swap(arr + l++, arr + r--);
	}
	if (l < n - 1)
		ft_qsort(arr + l, n - l);
	if (r > 0)
		ft_qsort(arr, r + 1);
}

static int	find_index(int *arr, size_t n, int value)
{
	size_t	l;
	size_t	r;
	size_t	m;

	l = 0;
	r = n;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (arr[m] > value)
			r = m;
		else
			l = m;
	}
	return (l);
}

static int	check_dublicates(int *arr, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] == arr[i - 1])
		{
			free(arr);
			return (0);
		}
		++i;
	}
	return (1);
}

int	shrink(int *arr, size_t n)
{
	int		*rec;
	size_t	i;

	rec = malloc(n * sizeof(int));
	if (!rec)
	{
		free(arr);
		return (0);
	}
	ft_memcpy(rec, arr, n * sizeof(int));
	if (n > 1)
		ft_qsort(rec, n);
	if (!check_dublicates(rec, n))
	{
		free(arr);
		return (0);
	}
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(rec, n, arr[i]);
		++i;
	}
	free (rec);
	return (1);
}
