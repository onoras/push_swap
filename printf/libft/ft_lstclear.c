/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:28:19 by onoras            #+#    #+#             */
/*   Updated: 2025/10/28 15:21:53 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nextnode;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		nextnode = node->next;
		del(node->content);
		free(node);
		node = nextnode;
	}
	*lst = NULL;
}
