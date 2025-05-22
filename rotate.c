/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:20:45 by jinwpark          #+#    #+#             */
/*   Updated: 2025/05/20 17:21:44 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*last;
	t_list	*first;

	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rb(t_list **b)
{
	ra(b);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
