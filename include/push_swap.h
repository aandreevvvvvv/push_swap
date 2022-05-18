/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:45:27 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/27 12:47:16 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_dlist
{
	unsigned int	content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

int		*parse(int argc, char **argv, size_t *n);
int		shrink(int *arr, size_t n);
int		sort(int *arr, size_t n);
int		error(void);

t_dlist	*lstnew(int content);
void	lstadd_front(t_dlist **lst, t_dlist *new);
void	*lstclear(t_dlist *cur, t_dlist *start);
void	lstdel(t_dlist **cur);

void	swap(t_dlist *lst, char c);
void	push(t_dlist **from, t_dlist **to, char c);
void	rotate(t_dlist **lst, char c);
void	reverse_rotate(t_dlist **lst, char c);

int		find(t_dlist *lst, unsigned int min, unsigned int max);
void	move(t_dlist **lst, int moves, char c);

void	push_chunk(t_dlist **a, t_dlist **b, size_t n);
void	sort_chunk(t_dlist **a, t_dlist **b, size_t n);
void	sort_small(t_dlist **a, t_dlist **b, size_t n);

#endif