/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:29:55 by onoras            #+#    #+#             */
/*   Updated: 2025/12/18 00:04:49 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

int	*copy_values(int *values, int count)
{
	int	*sorted;
	int	i;

	i = 0;
	sorted = malloc(sizeof(int) * count);
	if (!sorted)
		return (NULL);
	while (i < count)
	{
		sorted[i] = values[i];
		i++;
	}
	return (sorted);
}

void	map_index(int *values, int *sorted, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (j < count)
		{
			if (values[i] == sorted[j])
			{
				values[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	sort_bubble(int	*s, int c)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 0;
	while (i < c)
	{
		while (j < c - i -1)
		{
			if (s[j] > s[j + 1])
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	index_values(int *values, int count)
{
	int	*sorted;

	sorted = copy_values(values, count);
	if (!sorted)
		return ;
	sort_bubble(sorted, count);
	map_index(values, sorted, count);
	free(sorted);
}
