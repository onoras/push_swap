/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:33:00 by onoras            #+#    #+#             */
/*   Updated: 2025/10/28 09:41:02 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*srcv;
	unsigned char		*str;
	const unsigned char	*tempsrc;
	unsigned char		*tempstr;

	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	srcv = (const unsigned char *)src;
	if (str < srcv)
		while (n--)
			*str++ = *srcv++;
	else
	{
		tempsrc = srcv + (n - 1);
		tempstr = str + (n - 1);
		while (n--)
			*tempstr-- = *tempsrc--;
	}
	return (dest);
}
