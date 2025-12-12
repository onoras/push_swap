/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:42:54 by onoras            #+#    #+#             */
/*   Updated: 2025/10/28 12:55:52 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_sub(char const *s, char c);
static const char	*ft_skip(const char *s, char c, int skippy);
static void			ft_free(char **s, int i3);

char	**ft_split(char const *s, char c)
{
	char		**str;
	const char	*s1;
	const char	*ptr;
	int			i3;

	ptr = s;
	i3 = 0;
	str = malloc((ft_sub(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (*ptr)
	{
		ptr = ft_skip(ptr, c, 1);
		if (*ptr)
		{
			s1 = ptr;
			ptr = ft_skip(ptr, c, 0);
			str[i3] = ft_substr(s, s1 - s, ptr - s1);
			if (!str[i3++])
				return (ft_free(str, i3), NULL);
		}
	}
	str[i3] = NULL;
	return (str);
}

static int	ft_sub(char const *s, char c)
{
	int	i;
	int	substr;

	if (s == NULL)
		return (0);
	substr = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			substr++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (substr);
}

static const char	*ft_skip(const char *s, char c, int skippy)
{
	if (skippy)
		while (*s == c)
			s++;
	else
		while (*s && *s != c)
			s++;
	return (s);
}

static void	ft_free(char **s, int i3)
{
	int	i;

	i = 0;
	while (i < i3)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
