/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:30:41 by onoras            #+#    #+#             */
/*   Updated: 2025/12/19 16:07:25 by onoras           ###   ########.fr       */
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

typedef struct s_rotate
{
	int	cost;
	int	dir;
}	t_rotate;

typedef struct s_move
{
	int			total_cost;
	int			cost_a;
	int			cost_b;
	int			dir_a;
	int			dir_b;
	int			pos_b;
}	t_move;

int			parse_args(char **argv, int argc, int **out_values, int *out_count);
int			validate(const char *s, int *out);
int			check_duplis(const int *values, int c);
int			parse_digits(const char *s, int i, int sign, int *out);

void		push(t_stack *dst, t_stack *src);
void		swap(t_stack *s);
void		rotate(t_stack *s);
void		reverse_rotate(t_stack *s);

void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *b, t_stack *a);
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		reverse_rotate_a(t_stack *a);
void		reverse_rotate_b(t_stack *b);

void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		sort_two(t_stack *s);
void		sort_three(t_stack *s);
void		sort_five(t_stack *a, t_stack *b);
void		big_sort(t_stack *a, t_stack *b);
void		median_push(t_stack *a, t_stack *b);
void		cheap_move(t_stack *a, t_stack *b);
void		rotate_to_min(t_stack *a);
void		execute_move(t_stack *a, t_stack *b, t_move move);
t_rotate	get_cheapest_rotate(int pos, int size);

int			idx(const t_stack *s, int logical_index);
void		index_values(int *values, int count);
void		sort_bubble(int	*s, int c);

#endif
