/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:14:06 by onoras            #+#    #+#             */
/*   Updated: 2025/12/19 15:51:55 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_rotate	get_cheapest_rotate(int pos, int size)
{
	t_rotate	r;

	if (pos <= size / 2)
	{
		r.cost = pos;
		r.dir = 1;
	}
	else
	{
		r.cost = size - pos;
		r.dir = -1;
	}
	return (r);
}

t_rotate	find_insert(t_stack *a, int value_b)
{
	int	i;
	int	idx;
	int	val;
	int	best_pos;
	int	min_pos;

	i = 0;
	idx = a->t;
	best_pos = -1;
	min_pos = 0;
	while (i < a->s)
	{
		val = a->d[idx];
		if (val < a->d[(a->t + min_pos) % a->e])
			min_pos = i;
		if (val > value_b
			&& (best_pos == -1
				|| val < a->d[(a->t + best_pos) % a->e]))
			best_pos = i;
		idx = (idx + 1) % a->e;
		i++;
	}
	if (best_pos == -1)
		best_pos = min_pos;
	return (get_cheapest_rotate(best_pos, a->s));
}

static t_move	compute_move(t_stack *a, t_stack *b, int pos_b)
{
	t_move		move;
	t_rotate	rot;

	rot = get_cheapest_rotate(pos_b, b->s);
	move.cost_b = rot.cost;
	move.dir_b = rot.dir;
	move.pos_b = pos_b;
	rot = find_insert(a, b->d[(b->t + pos_b) % b->e]);
	move.cost_a = rot.cost;
	move.dir_a = rot.dir;
	if (move.dir_a == move.dir_b)
	{
		if (move.cost_a > move.cost_b)
			move.total_cost = move.cost_a;
		else
			move.total_cost = move.cost_b;
	}
	else
		move.total_cost = move.cost_a + move.cost_b;
	return (move);
}

void	cheap_move(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	curr;
	int		i;

	i = 0;
	best.total_cost = INT_MAX;
	while (i < b->s)
	{
		curr = compute_move(a, b, i);
		if (curr.total_cost < best.total_cost)
			best = curr;
		i++;
	}
	execute_move(a, b, best);
}
