#include "libft/libft.h"
#include "push_swap.h"
void sa(s_list **a)
{
    s_list *first;
    s_list *second;
    int tmp;

    first = *a;
    second = first->next;
    tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}
void ss(s_list **a, s_list **b)
{
    sa(a);
    sa(b);
}
void pa(s_list **a, s_list **b)
{
    

}
void pb(s_list **b)
{

}
void ra(s_list **a)
{

}
void rb(s_list **b)
{

}

void rr(s_list **a, s_list **b)
{

}
void rra(s_list **a)
{
    
}
void rrb(s_list **b)
{
    
}
void rrr(s_list **a, s_list **b)
{

}