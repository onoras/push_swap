/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:24:17 by onoras            #+#    #+#             */
/*   Updated: 2025/12/18 00:26:23 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	swap_a(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}
