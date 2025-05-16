/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:22:06 by jinwpark          #+#    #+#             */
/*   Updated: 2025/05/16 23:46:27 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

long	*check_part_one(char *str, int *count)
{
	size_t	i;
	long	*arr;
	char	**split_str;

	i = 0;
	*count = 0;
	while (i < ft_strlen(str))
	{
		if (!((str[i] >= '0' && str[i] <= '9') || \
str[i] == '-' || str[i] == '+' || str[i] == ' '))
			return (NULL);
		i++;
	}
	split_str = ft_split(str, ' ');
	while (split_str[*count])
		(*count)++;
	arr = malloc(sizeof(long) * (*count));
	i = 0;
	while (i < *count)
		arr[i] = ft_atol(split_str[i++]);
	free_split(split_str);
	return (arr);
}

int	*check_part_two(long *primo, int count)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	while (primo[i])
	{
		if (primo[i] > INT_MAX || primo[i] < INT_MIN)
			return (NULL);
		j = i + 1;
		while (primo[j])
		{
			if (primo[i] == primo[j])
				return (NULL);
			j++;
		}
		i++;
	}
	arr = malloc(sizeof(int) * i);
	arr = jw_intcpy(arr, primo, i);
	return (arr);
}

char	*make_str(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	long	*primo;
	int		*arr;
	Info	info;

	str = make_str(argc, argv);
	primo = check_part_one(str, &info.len);
	free(str);
	info.arr = check_part_two(primo, info.len);
	if (primo == NULL || info.arr == NULL || argc == 1)
	{
		free(arr);
		free(primo);
		write(1, "error\n", 6);
		return (0);
	}
	run_sort(info);
}
