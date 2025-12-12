/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:10:50 by onoras            #+#    #+#             */
/*   Updated: 2025/12/12 14:08:17 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

int	process_tokens(char **tokens, int *out_values, int *out_count)
{
	int	i;
	int	tmp;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (!validate(tokens[i], &tmp))
			return (0);
		out_values[*out_count] = tmp;
		(*out_count)++;
		i++;
	}
	return (1);
}

void	free_split(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	fill_values(char **argv, int argc, int *out_values, int *out_count)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (tokens == NULL)
			return (free(out_values), 0);
		if (!process_tokens(tokens, out_values, out_count))
		{
			free_split(tokens);
			return (0);
		}
		free_split(tokens);
		i++;
	}
	return (1);
}

int	count_tokens(char **argv, int argc)
{
	int		total;
	char	**tokens;
	int		i;
	int		j;

	total = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j] != NULL)
		{
			total++;
			j++;
		}
		free_split(tokens);
		i++;
	}
	return (total);
}

int	parse_args(char **argv, int argc, int **out_values, int *out_count)
{
	int	total;

	total = count_tokens(argv, argc);
	if (total <= 0)
		return (0);
	*out_values = malloc(total * sizeof(int));
	if (!*out_values)
		return (0);
	*out_count = 0;
	if (!fill_values(argv, argc, *out_values, out_count))
		return (free(*out_values), 0);
	return (1);
}
