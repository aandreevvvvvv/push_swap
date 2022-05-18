/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:05:16 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 16:47:29 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*arr;
	size_t	n;

	if (argc < 2)
		return (0);
	arr = parse(argc - 1, argv + 1, &n);
	if (!arr)
		return (error());
	if (check_dublicates(arr, n))
		return (error());
	if (!sort(arr, n))
		return (error());
	return (0);
}
	