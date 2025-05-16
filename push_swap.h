#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
typedef struct s_list
{
    int data; 
    struct s_list *next; 
} s_list;

typedef struct Info
{
    int *arr;
    int len;
} Info;
long *check_part_one(char *str, int *count);
long	ft_atol(const	char	*str);
char *make_str(int argc, char *argv[]);
int *jw_intcpy(int *dest, long *src, int len);
int *check_part_two(long *primo, int count);
s_list *ft_lstnew(int data);;
s_list add_node(s_list **node, s_list *new);
void	free_split(char **split);
void    free_list(s_list **node);
void sa(s_list **a);
void ss(s_list **a, s_list **b);
void pa(s_list **a, s_list **b);
void pb(s_list **b);
void ra(s_list **a);
void rb(s_list **b);
void rr(s_list **a, s_list **b);
void rra(s_list **a);
void rrb(s_list **b);
void rrr(s_list **a, s_list **b);

#endif