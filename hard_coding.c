/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:20:53 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/11 00:21:47 by jinwpark         ###   ########.fr       */
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
	int	max_idx;
	int	*new_arr;
	int	i;

	max_idx = 0;
	i = 0;
	while (++i < 4)
		if (arr[i] > arr[max_idx])
			max_idx = i;
	sort_4_case(arr, max_idx);
	write(1, "pb\n", 3);
	new_arr = push(arr, arr[0], 4);
	sort_3(new_arr);
	write(1, "pa\nra\n", 6);
	free(new_arr);
}

void	sort_5(int *arr)
{
	int	min_idx;
	int	i;
	int	*tmp1;

	i = -1;
	min_idx = 0;
	while (++i < 5)
		if (arr[i] < arr[min_idx])
			min_idx = i;
	case_5_rotate(arr, 5, min_idx);
	write(1, "pb\n", 3);
	tmp1 = push(arr, arr[0], 5);
	sort_4(tmp1);
	write(1, "pa\npa\n", 6);
	free(tmp1);
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
