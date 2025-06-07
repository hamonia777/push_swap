/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:17:53 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/07 23:41:39 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = NULL;
	last = *a;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	first->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_list **b)
{
	rra(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
