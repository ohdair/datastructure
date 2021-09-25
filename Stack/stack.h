#ifndef _STACK_
# define _STACK_

#include "../list/linked_list.h"

typedef struct _stack {
    t_linked_list_node *top;
    int count;
} Stack;

Stack *init(void);
void ft_push(t_linked_list *pList, int data);
void ft_pop(t_linked_list *pList);
int ft_peek(t_linked_list *pList);

#endif
