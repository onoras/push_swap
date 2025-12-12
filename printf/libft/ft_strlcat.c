/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:35:41 by onoras            #+#    #+#             */
/*   Updated: 2025/10/24 15:51:20 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	temp;

	temp = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (d >= size)
		return (size + s);
	temp = s + d;
	s = 0;
	while (src[s] != '\0' && d < size - 1)
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (temp);
}
