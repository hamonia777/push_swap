/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:31:32 by jinwpark          #+#    #+#             */
/*   Updated: 2025/05/20 23:05:34 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*index_mapping(int *arr, int len)
{
	int	*sorted;
	int	*indexed;
	int	i, j;

	sorted = malloc(sizeof(int) * len);
	indexed = malloc(sizeof(int) * len);
	if (!sorted || !indexed)
		return (NULL);

	for (i = 0; i < len; i++)
		sorted[i] = arr[i];
	for (i = 0; i < len - 1; i++)
		for (j = i + 1; j < len; j++)
			if (sorted[i] > sorted[j])
			{
				int tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			if (arr[i] == sorted[j])
				indexed[i] = j;
	}
	free(sorted);
	return (indexed);
}

int get_max_bits(int max)
{
	int bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	run_sort(int *arr, int len)
{
	t_list *a = NULL;
	t_list *b = NULL;
	int		*iarr = index_mapping(arr, len);
	int		max_bits = get_max_bits(len - 1);
	int		i, j;

	for (i = 0; i < len; i++)
		add_node(&a, ft_lstnew(iarr[i]));

	for (i = 0; i < max_bits; i++)
	{
		j = 0;
		while (j++ < len)
		{
			if (((a->data >> i) & 1) == 0)
			{
				pb(&a, &b);
				write(1, "pb\n", 3);
			}
			else
			{
				ra(&a);
				write(1, "ra\n", 3);
			}
		}
		while (b)
		{
			pa(&a, &b);
			write(1, "pa\n", 3);
		}
	}
	free(iarr);
	free_list(&a);
}
