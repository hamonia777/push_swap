/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:31:32 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/11 20:03:23 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_round(t_list **a, t_list **b, int bit, int len)
{
	int	j;

	j = 0;
	while (j++ < len)
	{
		if ((((*a)->data >> bit) & 1) == 0)
		{
			pb(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
	while (*b)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
}

int	is_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	run_sort(int *arr, int len)
{
	t_list	*a;
	t_list	*b;
	int		*iarr;
	int		max_bits;
	int		i;

	a = NULL;
	b = NULL;
	iarr = index_mapping(arr, len);
	max_bits = get_max_bits(len - 1);
	i = 0;
	while (i < len)
		add_node(&a, ft_lstnew(iarr[i++]));
	if (len <= 5)
		hard_coding(iarr, len);
	else
	{
		i = 0;
		while (i < max_bits)
			radix_round(&a, &b, i++, len);
	}
	free(iarr);
	free_list(&a);
}
