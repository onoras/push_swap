/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:02:38 by onoras            #+#    #+#             */
/*   Updated: 2025/12/12 13:39:08 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

void	init_stack(t_stack *s, int capacity)
{
	s->data = malloc(sizeof(int) * capacity);
	if (!s->data)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	s->size = 0;
	s->elements = capacity;
	s->top = 0;
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
	while (i < stack->size)
	{
		ft_printf("%d\n", stack->data[(stack->top + i) % stack->elements]);
		i++;
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
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stack(&a, count);
	init_stack(&b, count);
	i = 0;
	while (i < count)
	{
		a.data[i] = values[i];
		a.size++;
		i++;
	}
	print_stack(&a);
	return (0);
}
