/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_execs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:12:56 by onoras            #+#    #+#             */
/*   Updated: 2025/12/19 15:52:03 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_stack *a, t_stack *b, int count, int dir)
{
	while (count-- > 0)
	{
		if (dir == 1)
			rr(a, b);
		else
			rrr(a, b);
	}
}

static int	apply_common_rotations(t_stack *a, t_stack *b, t_move move)
{
	int	common;

	if (move.dir_a != move.dir_b)
		return (0);
	if (move.cost_a < move.cost_b)
		common = move.cost_a;
	else
		common = move.cost_b;
	do_rotate(a, b, common, move.dir_a);
	return (common);
}

static void	apply_remaining_a(t_stack *a, t_move move, int common)
{
	int	i;

	i = move.cost_a - common;
	while (i-- > 0)
	{
		if (move.dir_a == 1)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

static void	apply_remaining_b(t_stack *b, t_move move, int common)
{
	int	i;

	i = move.cost_b - common;
	while (i-- > 0)
	{
		if (move.dir_b == 1)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
}

void	execute_move(t_stack *a, t_stack *b, t_move move)
{
	int	common;

	common = apply_common_rotations(a, b, move);
	apply_remaining_a(a, move, common);
	apply_remaining_b(b, move, common);
	push_a(a, b);
}
