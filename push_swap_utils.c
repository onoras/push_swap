/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:05:47 by onoras            #+#    #+#             */
/*   Updated: 2025/12/10 12:27:19 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	idx(t_stack *s, int logical_index)
{
	return ((s->top + logical_index) % s->elements);
}

void	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->data[idx(s, 0)];
	s->data[idx(s, 0)] = s->data[idx(s, 1)];
	s->data[idx(s, 1)] = tmp;
}

void	push(t_stack *dst, t_stack *src)
{
	int	tmp;

	if (src->size == 0)
		return ;
	tmp = src->data[idx(src, 0)];
	src->top = (src->top + 1) % src->elements;
	src->size--;
	dst->top = (dst->top - 1 + dst->elements) % dst->elements;
	dst->data[idx(dst, 0)] = tmp;
	dst->size++;
}

void	rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = (s->top + 1) % s->elements;
}

void	reverse_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = (s->top - 1 + s->elements) % s->elements;
}
