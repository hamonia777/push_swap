/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <jinwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:18:25 by jinwpark          #+#    #+#             */
/*   Updated: 2025/05/20 23:23:36 by jinwpark         ###   ########.fr       */
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
int	*check_part_two(long *one, int len);
int	init(int *arr, int start, int end);
int is_sorted(int *arr,int len);
t_list	*ft_lstnew(int data);
t_list	*find_node(t_list *node, int index);
void	delete_node(t_list **node);
void	add_node(t_list **node, t_list *new);
void	free_split(char **split);
void	free_list(t_list **node);
void	sa(t_list **a);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	quick_sort(int *arr, int start, int end);
void	swap(int *a, int *b);
void	run_sort(int *arr, int len);

#endif
