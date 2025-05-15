#include "libft/libft.h"
#include "push_swap.h"

s_list *ft_lstnew(int data);
{
    s_list *list;

    list = (s_list *)malloc(sizeof(s_list));
    if (!list)
        return (NULL);
    list->data = data;
    list->next = NULL;
    return (list);
}

s_list add_node(s_list **node, s_list *new)
{
    new->next = *node;
    *node = new;
}

void    free_list(s_list **node)
{
    s_list  *tmp;

    while (*node)
    {
        tmp = (*node)->next;
        free(*node);
        *lst = tmp;
    }
    *node = NULL;
}