/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:30 by onoras            #+#    #+#             */
/*   Updated: 2025/10/22 10:56:25 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isspace(int str);
static int	ft_isneg(int neg);
static int	ft_inner_atoi(const char *str);

int	ft_atoi(const char *ptr)
{
	int	nbr;
	int	minus;

	nbr = 0;
	while (ft_isspace(*ptr))
		ptr++;
	while (ft_isneg(*ptr))
	{
		minus = ft_isneg(*ptr);
		if (minus == 1 || minus == 2)
		{
			ptr++;
			break ;
		}
	}
	nbr = ft_inner_atoi(ptr);
	if (minus == 1)
		nbr = -nbr;
	return (nbr);
}

static int	ft_isspace(int str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	else
		return (0);
}

static int	ft_isneg(int neg)
{
	if (neg == '-')
		return (1);
	else if (neg == '+')
		return (2);
	else
		return (0);
}

static int	ft_inner_atoi(const char *str)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(*str))
	{
		if (*str == '0')
			nbr = nbr * 10;
		else
			nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr);
}
