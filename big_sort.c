/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 01:02:30 by onoras            #+#    #+#             */
/*   Updated: 2025/12/18 15:58:37 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

void	big_sort(t_stack *a, t_stack*b)
{
	median_push(a, b);
	while (a->s > 3)
		push_b(b, a);
	sort_three(a);
	while (b->s)
		cheap_move();
	rotate_to_min(a);
}









// void	radix_sort(t_stack *a, t_stack *b)
// {
// 	int	max_bits;
// 	int	bit;
// 	int	size;
// 	int	chunk_size;

// 	chunk_size = 1;
// 	max_bits = 0;
// 	size = a->s -1;
// 	while ((size >> max_bits) != 0)
// 		max_bits++;
// 	bit = 0;
// 	while (bit < max_bits)
// 	{
// 		size = a->s;
// 		while (size-- > 0)
// 		{
// 			int chunk = (a->d[idx(a, 0)] >> bit) & ((1 << chunk_size) - 1);
// 			if (chunk == 0)
// 				push_b(b, a);
// 			else
// 				rotate_a(a);
// 		}
// 		while (b->s > 0)
// 			push_a(a, b);
// 		bit += chunk_size;
// 	}
// }

