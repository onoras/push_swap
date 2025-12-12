/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:39:20 by onoras            #+#    #+#             */
/*   Updated: 2025/10/23 16:18:39 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	pt = malloc(size * nmemb);
	if (!pt)
		return (NULL);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
