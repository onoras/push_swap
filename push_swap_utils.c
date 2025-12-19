/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:05:47 by onoras            #+#    #+#             */
/*   Updated: 2025/12/19 16:04:36 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	idx(const t_stack *s, int logical_index)
{
	return ((s->t + logical_index) % s->e);
}

void	swap(t_stack *s)
{
	int	tmp;

	if (s->s < 2)
		return ;
	tmp = s->d[idx(s, 0)];
	s->d[idx(s, 0)] = s->d[idx(s, 1)];
	s->d[idx(s, 1)] = tmp;
}

void	push(t_stack *dst, t_stack *src)
{
	if (src->s == 0)
		return ;
	dst->t = (dst->t - 1 + dst->e) % dst->e;
	dst->d[dst->t] = src->d[idx(src, 0)];
	dst->s++;
	src->t = (src->t + 1) % src->e;
	src->s--;
}

void	rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->s < 2)
		return ;
	tmp = s->d[idx(s, 0)];
	i = 0;
	while (i < s->s - 1)
	{
		s->d[idx(s, i)] = s->d[idx(s, i + 1)];
		i++;
	}
	s->d[idx(s, s->s - 1)] = tmp;
}

void	reverse_rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->s < 2)
		return ;
	tmp = s->d[idx(s, s->s - 1)];
	i = s->s - 1;
	while (i > 0)
	{
		s->d[idx(s, i)] = s->d[idx(s, i - 1)];
		i--;
	}
	s->d[idx(s, 0)] = tmp;
}
