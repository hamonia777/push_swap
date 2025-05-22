/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:22:15 by jinwpark          #+#    #+#             */
/*   Updated: 2025/05/20 23:09:05 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_list **b)
{
	sa(b);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
