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

void	run_sort(int *arr, int len)
{
	quick_sort(arr, 0, len - 1);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	init(int *arr, int start, int end)
{
	int	pivot;
	int	left;
	int	right;

	left = start + 1;
	right = end;
	pivot = arr[start];
	while (left < right)
	{
		while (left <= right && arr[left] <= pivot)
			left++;
		while (left <= right && arr[right] > pivot)
			right--;
		if (left < right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	swap(&arr[start], &arr[right]);
	return (right);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = init(arr, start, end);
		quick_sort(arr, start, pivot - 1);
		quick_sort(arr, pivot + 1, end);
	}
}

// #include<stdio.h>
// int main()
// {
//     int a[] = {1,3,2,6,0,4};
//     int i = 0;

//     quick_sort(a,0,6);

//     while(i<6)
//     {
//         printf("%d ",a[i]);
//         i++;
//     }
// }
