/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:43:34 by onoras            #+#    #+#             */
/*   Updated: 2025/10/27 16:49:59 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static struct s_mydigsneg	ft_digsandneg(long n);

char	*ft_itoa(int n)
{
	struct s_mydigsneg	din;
	char				*arr;
	long				num;
	int					i;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	din = ft_digsandneg(num);
	i = din.digs + din.neg - 1;
	if (num < 0)
		num = -num;
	arr = (char *)malloc(din.digs + din.neg + 1);
	if (arr == NULL)
		return (NULL);
	arr[din.digs + din.neg] = '\0';
	while (num > 0)
	{
		arr[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	if (din.neg == 1)
		arr[0] = '-';
	return (arr);
}

static struct s_mydigsneg	ft_digsandneg(long n)
{
	struct s_mydigsneg	dn;
	long				i;

	dn.digs = 0;
	dn.neg = 0;
	i = n;
	if (i < 0)
	{
		dn.neg = 1;
		i = -i;
	}
	while (i)
	{
		dn.digs++;
		i /= 10;
	}
	return (dn);
}
