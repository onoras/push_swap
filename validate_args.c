/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:02:53 by onoras            #+#    #+#             */
/*   Updated: 2025/12/19 16:04:59 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	skip_sign(const char *s, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	parse_digits(const char *s, int i, int sign, int *out)
{
	long	result;
	long	test;

	result = 0;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
	{
		test = result * 10 + (s[i] - '0');
		if ((sign == 1 && test > INT_MAX)
			|| (sign == -1 && test > (long)INT_MAX + 1))
			return (0);
		result = test;
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*out = (int)(result * sign);
	return (1);
}

int	validate(const char *s, int *out)
{
	int	i;
	int	sign;

	i = skip_sign(s, &sign);
	if (!parse_digits(s, i, sign, out))
		return (0);
	return (1);
}

int	check_duplis(const int *values, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c)
	{
		j = i + 1;
		while (j < c)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
