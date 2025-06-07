/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:43:53 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/07 23:38:06 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void	add_node(t_list **node, t_list *new)
{
	t_list	*cur;

	if (!*node)
	{
		*node = new;
		return ;
	}
	cur = *node;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	delete_node(t_list **node)
{
	t_list	*prev;
	t_list	*cur;

	if (!node || !*node)
		return ;
	cur = *node;
	prev = NULL;
	if (cur->next == NULL)
	{
		free(cur);
		*node = NULL;
		return ;
	}
	while (*node)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	prev->next = NULL;
}

t_list	*find_node(t_list *node, int index)
{
	t_list	*new;
	int		i;

	i = 0;
	new = node;
	while (new && i < index)
	{
		new = new->next;
		i++;
	}
	return (new);
}

void	free_list(t_list **node)
{
	t_list	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
	*node = NULL;
}
