/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:45:18 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 16:47:36 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*arr;
	size_t	n;

	if (argc < 2)
		return (0);
	arr = parse(argc - 1, argv + 1, &n);
	if (!arr)
		return (error());
	if (!shrink(arr, n))
		return (error());
	if (!sort(arr, n))
		return (error());
	return (0);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
