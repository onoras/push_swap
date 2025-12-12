/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:31:27 by onoras            #+#    #+#             */
/*   Updated: 2025/10/23 11:59:07 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		nv;
	int		size;
	char	*str;

	str = s;
	nv = c;
	size = n;
	while (size-- > 0)
	{
		*str++ = nv;
	}
	return (s);
}
