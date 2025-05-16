/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:43:53 by jinwpark          #+#    #+#             */
/*   Updated: 2025/05/16 22:52:25 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

s_list	*ft_lstnew(int data)
{
	s_list	*list;

	list = (s_list *)malloc(sizeof(s_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

s_list	add_node(s_list **node, s_list *new)
{
	new->next = *node;
	*node = new;
}

void	free_list(s_list **node)
{
	s_list	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
	*node = NULL;
}
