/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:30:41 by onoras            #+#    #+#             */
/*   Updated: 2025/12/18 01:20:23 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	*d;
	int	s;
	int	e;
	int	t;
}	t_stack;

int		parse_args(char **argv, int argc, int **out_values, int *out_count);
int		validate(const char *s, int *out);
int		check_duplis(int *values, int c);
int		parse_digits(const char *s, int i, int sign, int *out);
void	push(t_stack *dst, t_stack *src);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	reverse_rotate_a(t_stack *a);
void	push_b(t_stack *b, t_stack *a);
void	rotate_b(t_stack *b);
void	reverse_rotate_b(t_stack *b);
void	sort_two(t_stack *s);
void	sort_three(t_stack *s);
void	sort_five(t_stack *a, t_stack *b);
int		idx(t_stack *s, int logical_index);
void	print_stack(t_stack *stack);
void	index_values(int *values, int count);
void	radix_sort(t_stack *a, t_stack *b);

#endif
