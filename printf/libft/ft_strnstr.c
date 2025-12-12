/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:42:25 by onoras            #+#    #+#             */
/*   Updated: 2025/10/24 16:55:05 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bs, const char *ls, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (ls[j] == '\0')
		return ((char *)bs);
	while (bs[i] != '\0')
	{
		while (bs[i + j] == ls[j] && ls[j] != '\0' && (i + j) < len)
		{
			j++;
			if (ls[j] == '\0')
				return ((char *)&bs[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
