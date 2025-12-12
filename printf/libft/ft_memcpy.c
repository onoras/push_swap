/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:32:33 by onoras            #+#    #+#             */
/*   Updated: 2025/10/28 09:40:54 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*srcv;
	unsigned char		*str;

	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	srcv = (const unsigned char *)src;
	while (n--)
		*str++ = *srcv++;
	return (dest);
}
