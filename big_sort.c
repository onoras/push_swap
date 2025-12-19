/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 01:02:30 by onoras            #+#    #+#             */
/*   Updated: 2025/12/19 15:51:38 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*copy_stack_values(t_stack *s)
{
	int	*values;
	int	i;
	int	idx;

	values = malloc(sizeof(int) * s->s);
	if (!values)
		return (NULL);
	i = 0;
	idx = s->t;
	while (i < s->s)
	{
		values[i] = s->d[idx];
		i++;
		idx = (idx + 1) % s->e;
	}
	return (values);
}

void	median_push(t_stack *a, t_stack *b)
{
	int	median;
	int	to_push;
	int	pushed;
	int	*values;
	int	size;

	size = a->s;
	values = copy_stack_values(a);
	if (!values)
		return ;
	sort_bubble(values, size);
	median = values[size / 2];
	free(values);
	pushed = 0;
	to_push = a->s / 2;
	while (pushed < to_push)
	{
		if (a->d[a->t] <= median)
		{
			push_b(b, a);
			pushed++;
		}
		else
			rotate_a(a);
	}
}

void	rotate_to_min(t_stack *a)
{
	int			i;
	int			idx;
	int			min_pos;
	t_rotate	rot;

	if (a->s == 0)
		return ;
	i = 0;
	idx = a->t;
	min_pos = 0;
	while (i < a->s)
	{
		if (a->d[idx] < a->d[(a->t + min_pos) % a->e])
			min_pos = i;
		idx = (idx + 1) % a->e;
		i++;
	}
	rot = get_cheapest_rotate(min_pos, a->s);
	while (rot.cost-- > 0)
	{
		if (rot.dir == 1)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	big_sort(t_stack *a, t_stack*b)
{
	median_push(a, b);
	while (a->s > 3)
		push_b(b, a);
	sort_three(a);
	while (b->s)
		cheap_move(a, b);
	rotate_to_min(a);
}
