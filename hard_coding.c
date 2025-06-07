/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:20:53 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/08 01:27:23 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_3(int *arr)
{
	int	a;
	int	b;
	int	c;

	a = arr[0];
	b = arr[1];
	c = arr[2];
	if (a > b && b < c && a < c)
		write(1, "sa\n", 3);
	else if (a > b && b > c)
		write(1, "sa\nrra\n", 7);
	else if (a > b && b < c && a > c)
		write(1, "ra\n", 3);
	else if (a < b && b > c && a < c)
		write(1, "sa\nra\n", 6);
	else if (a < b && b > c && a > c)
		write(1, "rra\n", 4);
}

void	sort_4(int *arr)
{
	int	i;
	int	min;
	int	min_idx;

	min = arr[0];
	min_idx = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_idx = i;
		}
		i++;
	}
	if (min_idx == 1)
		write(1, "ra\n", 3);
	else if (min_idx == 2)
		write(1, "ra\nra\n", 6);
	else if (min_idx == 3)
		write(1, "rra\n", 4);
	write(1, "pb\n", 3);
	sort_3(arr + (min_idx < 1));
	write(1, "pa\n", 3);
}

void	find_two_min(int *arr, int *idx1, int *idx2)
{
	int	i;
	int	min1;
	int	min2;

	i = 0;
	min1 = 2147483647;
	min2 = 2147483647;
	*idx1 = -1;
	*idx2 = -1;
	while (i < 5)
	{
		if (arr[i] < min1)
		{
			min2 = min1;
			*idx2 = *idx1;
			min1 = arr[i];
			*idx1 = i;
		}
		else if (arr[i] < min2)
		{
			min2 = arr[i];
			*idx2 = i;
		}
		i++;
	}
}

void	sort_5(int *arr)
{
	int	idx1;
	int	idx2;

	find_two_min(arr, &idx1, &idx2);
	write(1, "ra\npb\nra\npb\n", 12);
	sort_3(arr + 2);
	write(1, "pa\npa\n", 6);
}

void	hard_coding(int *arr, int len)
{
	if (len == 2)
		write(1, "ra\n", 3);
	else if (len == 3)
		sort_3(arr);
	else if (len == 4)
		sort_4(arr);
	else if (len == 5)
		sort_5(arr);
}
