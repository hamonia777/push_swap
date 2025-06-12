/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:18:40 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/11 00:25:01 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rotate(int *arr, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = arr[0];
	while (i < len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[len - 1] = tmp;
}

void	rev_rotate(int *arr, int len)
{
	int	tmp;
	int	i;

	i = len - 1;
	tmp = arr[len - 1];
	while (i > 0)
	{
		tmp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = tmp;
		i--;
	}
}

int	*push(int *arr, int num, int len)
{
	int	*new_arr;
	int	j;
	int	i;

	i = 0;
	j = 0;
	new_arr = malloc(sizeof(int) * (len - 1));
	if (!new_arr)
		return (NULL);
	while (i < len)
	{
		if (arr[i] != num)
			new_arr[j++] = arr[i];
		i++;
	}
	return (new_arr);
}

void	sort_4_case(int *arr, int max_idx)
{
	if (max_idx == 1)
	{
		rotate(arr, 4);
		write(1, "ra\n", 3);
	}
	else if (max_idx == 2)
	{
		rotate(arr, 4);
		write(1, "ra\n", 3);
		rotate(arr, 4);
		write(1, "ra\n", 3);
	}
	else if (max_idx == 3)
	{
		rev_rotate(arr, 4);
		write(1, "rra\n", 4);
	}
}

void	case_5_rotate(int *arr, int len, int idx)
{
	int	i;

	i = 0;
	if (idx <= len / 2)
	{
		while (i < idx)
		{
			rotate(arr, len);
			write(1, "ra\n", 3);
			i++;
		}
	}
	else
	{
		while (i < len - idx)
		{
			rev_rotate(arr, len);
			write(1, "rra\n", 4);
			i++;
		}
	}
}
