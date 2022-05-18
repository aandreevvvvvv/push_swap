/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:04:42 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/29 19:31:40 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

int		*parse(int argc, char **argv, size_t *n);
int		check_dublicates(int *arr, size_t n);
int		sort(int *arr, size_t n);

t_dlist	*arr_to_list(int *arr, size_t n);
int		is_sorted(t_dlist *lst);
int		do_operation(t_dlist **a, t_dlist **b, char *op);

t_dlist	*lstnew(int content);
void	lstadd_front(t_dlist **lst, t_dlist *new);
void	*lstclear(t_dlist *cur, t_dlist *start);
void	lstdel(t_dlist **cur);

void	swap(t_dlist *lst);
void	push(t_dlist **from, t_dlist **to);
int		rotate(t_dlist **lst);
int		reverse_rotate(t_dlist **lst);

char	*get_next_line(int fd);

#endif