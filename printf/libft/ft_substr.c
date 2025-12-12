/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:33:45 by onoras            #+#    #+#             */
/*   Updated: 2025/10/27 10:36:57 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	cpylen;

	if (s == NULL)
		return (NULL);
	cpylen = ft_strlen(s);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= cpylen)
		return (ft_strdup(""));
	if (len > cpylen - start)
		len = cpylen - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
