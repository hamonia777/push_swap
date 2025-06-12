/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:22:06 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/12 20:41:36 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

long	*jw_validate(long *arr, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && \
			str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (NULL);
		if ((str[i] == '+' || str[i] == '-') && \
			(str[i + 1] == '+' || str[i + 1] == '-'))
			return (NULL);
		if (str[i] >= '0' && str[i] <= '9')
		{
			if ((str[i + 1] == '+' || str[i + 1] == '-') || \
			(str[i + 1] >= 'a' && str[i + 1] <= 'z') || \
			(str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
				return (NULL);
		}
		if (9 <= str[i] && str[i] <= 13)
			return (NULL);
		i++;
	}
	return (arr);
}

long	*check_part_one(char *str, int *count)
{
	size_t	i;
	long	*arr;
	long	*tmp;
	char	**split_str;

	if (!str)
		return (NULL);
	*count = 0;
	split_str = ft_split(str, ' ');
	while (split_str[*count])
		(*count)++;
	arr = malloc(sizeof(long) * (*count));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < (size_t)(*count))
		arr[i] = ft_atol(split_str[i]);
	free_split(split_str);
	tmp = jw_validate(arr, str);
	if (!tmp)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

int	*check_part_two(long *one, int len)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	if (!one)
		return (NULL);
	while (i < len)
	{
		if (one[i] > INT_MAX || one[i] < INT_MIN)
			return (NULL);
		j = i + 1;
		while (j < len)
		{
			if (one[i] == one[j])
				return (NULL);
			j++;
		}
		i++;
	}
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	arr = jw_intcpy(arr, one, len);
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
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 1 && !ft_isdigit(str[0]))
		{
			free(str);
			str = NULL;
		}
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	long	*one;
	int		*arr;
	int		len;

	str = make_str(argc, argv);
	one = check_part_one(str, &len);
	free(str);
	arr = check_part_two(one, len);
	if (one == NULL || arr == NULL)
	{
		free(arr);
		free(one);
		write(1, "Error\n", 6);
		return (0);
	}
	if (!is_sorted(arr, len))
		run_sort(arr, len);
	free(arr);
	free(one);
	return (0);
}
