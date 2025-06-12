/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:18:25 by jinwpark          #+#    #+#             */
/*   Updated: 2025/06/11 00:25:53 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

typedef struct t_list
{
	struct t_list	*next;
	int				data;
}	t_list;

typedef struct t_info
{
	int	*arr;
	int	len;
}	t_info;

long	*check_part_one(char *str, int *count);
long	ft_atol(const	char	*str);
char	*make_str(int argc, char *argv[]);
int		*jw_intcpy(int *dest, long *src, int len);
int		*index_mapping(int *arr, int len);
int		*check_part_two(long *one, int len);
int		init(int *arr, int start, int end);
int		is_sorted(int *arr, int len);
int		*push(int *arr, int num, int len);
t_list	*ft_lstnew(int data);
void	hard_coding(int *arr, int len);
void	add_node(t_list **node, t_list *new);
void	free_split(char **split);
void	free_list(t_list **node);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	run_sort(int *arr, int len);
void	rotate(int *arr, int len);
void	rev_rotate(int *arr, int len);
void	sort_4_case(int *arr, int max_idx);
void	case_5_rotate(int *arr, int len, int idx);

#endif
