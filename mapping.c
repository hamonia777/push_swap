/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 23:35:27 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/08 00:36:28 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*intcpy(int *src, int len)
{
	int	i;
	int	*dest;

	dest = malloc(sizeof(int) * len);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexed_arr(int *arr, int *sorted, int *indexed, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] == sorted[j])
			{
				indexed[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	*index_mapping(int *arr, int len)
{
	int	*sorted;
	int	*indexed;

	indexed = malloc(sizeof(int) * len);
	if (!indexed)
		return (NULL);
	sorted = intcpy(arr, len);
	if (!sorted)
	{
		free(indexed);
		return (NULL);
	}
	bubble_sort(sorted, len);
	indexed_arr(arr, sorted, indexed, len);
	free(sorted);
	return (indexed);
}
