/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dublicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:17:38 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 15:37:48 by bgohan           ###   ########.fr       */
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

int	check_dublicates(int *arr, size_t n)
{
	int		*rec;
	size_t	i;

	rec = malloc(n * sizeof(int));
	if (!rec)
	{
		free(arr);
		return (1);
	}
	ft_memcpy(rec, arr, n * sizeof(int));
	if (n > 1)
		ft_qsort(rec, n);
	i = 1;
	while (i < n)
	{
		if (rec[i] == rec[i - 1])
		{
			free(rec);
			free(arr);
			return (1);
		}
		++i;
	}
	free (rec);
	return (0);
}
