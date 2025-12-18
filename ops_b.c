/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:24:27 by onoras            #+#    #+#             */
/*   Updated: 2025/12/18 00:25:44 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	swap_b(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	push_b(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_printf("pb\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}


