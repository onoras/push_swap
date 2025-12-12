/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:41:52 by onoras            #+#    #+#             */
/*   Updated: 2025/10/23 11:59:03 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	const unsigned char	*src1 = (const unsigned char *)s1;
	const unsigned char	*src2 = (const unsigned char *)s2;

	i = 0;
	while (n-- > 0)
	{
		if (src1[i] > src2[i])
			return (src1[i] - src2[i]);
		if (src1[i] < src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
