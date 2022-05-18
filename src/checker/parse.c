/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:46:31 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 16:11:59 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

static int	check_int(const char *arg)
{
	size_t	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		++i;
	if (arg[i] == 0)
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		++i;
	}
	if (ft_strlen(arg) > 12)
		return (0);
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	return (1);
}

int	*parse(int argc, char **argv, size_t *n)
{
	size_t	i;
	int		*arr;

	if (argc < 1)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		if (!check_int(argv[i++]))
			return (NULL);
	}
	*n = i;
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		arr[i] = ft_atoi(argv[i]);
		++i;
	}
	return (arr);
}
