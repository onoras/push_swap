/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:27:53 by onoras            #+#    #+#             */
/*   Updated: 2025/10/28 14:55:45 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		if (node->content != del)
		{
			del(node->content);
			free(lst);
			break ;
		}
		node = node->next;
	}
}
