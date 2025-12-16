/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:58:46 by onoras            #+#    #+#             */
/*   Updated: 2025/12/16 17:44:17 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


int	find_min_index(t_stack *a)
{
	int	tmp;
	int	i;
	int	min_idx;

	min_idx = 0;
	i = 1;
	tmp = a->d[idx(a, 0)];
	while (i < a->s)
	{
		if (tmp > a->d[idx(a, i)])
		{
			tmp = a->d[idx(a, i)];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	rotations;
	int	i;

	min_idx = find_min_index(a);
	if (min_idx <= a->s / 2)
	{
		i = 0;
		while (i < min_idx)
		{
			rotate(a);
			i++;
		}
	}
	else
	{
		rotations = a->s - min_idx;
		i = 0;
		while (i < rotations)
		{
			reverse_rotate(a);
			i++;
		}
	}
	push(b, a);
}

void	sort_two(t_stack *s)
{
	if (s->d[idx(s, 0)] > s->d[idx(s, 1)])
		swap(s);
}

void	sort_three(t_stack *s)
{
	if (s->d[idx(s, 0)] > s->d[idx(s, 1)] && s->d[idx(s, 1)] < s->d[idx(s, 2)]
		&& s->d[idx(s, 0)] < s->d[idx(s, 2)])
		swap(s);
	else if (s->d[idx(s, 0)] > s->d[idx(s, 1)]
		&& s->d[idx(s, 1)] > s->d[idx(s, 2)])
	{
		swap(s);
		reverse_rotate(s);
	}
	else if (s->d[idx(s, 0)] > s->d[idx(s, 1)] && s->d[idx(s, 1)]
		< s->d[idx(s, 2)] && s->d[idx(s, 0)] > s->d[idx(s, 2)])
		rotate(s);
	else if (s->d[idx(s, 0)] < s->d[idx(s, 1)] && s->d[idx(s, 1)]
		> s->d[idx(s, 2)] && s->d[idx(s, 0)] < s->d[idx(s, 2)])
	{
		swap(s);
		rotate(s);
	}
	else if (s->d[idx(s, 0)] < s->d[idx(s, 1)] && s->d[idx(s, 1)]
		> s->d[idx(s, 2)] && s->d[idx(s, 0)] > s->d[idx(s, 2)])
		reverse_rotate(s);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_three(a);
	push(a, b);
	push(a, b);
}

