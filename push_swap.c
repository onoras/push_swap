/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:02:38 by onoras            #+#    #+#             */
/*   Updated: 2025/12/18 15:57:07 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

void	init_stack(t_stack *s, int capacity)
{
	s->d = malloc(sizeof(int) * capacity);
	if (!s->d)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	s->s = 0;
	s->e = capacity;
	s->t = 0;
}

int	parse(char **argv, int argc, int **out_values, int *out_count)
{
	if (!parse_args(argv, argc, out_values, out_count))
		return (0);
	if (!check_duplis(*out_values, *out_count))
	{
		free(*out_values);
		return (0);
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->s)
	{
		ft_printf("%d\n", stack->d[(stack->t + i) % stack->e]);
		i++;
	}
}

void	size_parser(t_stack *a, t_stack *b)
{
	if (a->s == 2)
		sort_two(a);
	if (a->s == 3)
		sort_three(a);
	if (a->s == 5 || a->s == 4)
		sort_five(a, b);
	if (a->s > 5)
	{
		big_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		count;
	int		*values;
	int		i;

	if (!parse(argv, argc, &values, &count))
		return (write(2, "Error\n", 6), 1);
	init_stack(&a, count);
	init_stack(&b, count);
	index_values(values, count);
	i = 0;
	while (i < count)
	{
		a.d[i] = values[i];
		a.s++;
		i++;
	}
	size_parser(&a, &b);
	return (0);
}
