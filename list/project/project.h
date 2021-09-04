#ifndef LINKED_LIST_PLUS_H
# define LINKED_LIST_PLUS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_linked_list_node
{
	int 			coef;
	int				degree;
	struct 			s_linked_list_node	*next;
}				t_linked_list_node;

typedef struct	s_linked_list
{
	int					num_of_current_element;
	t_linked_list_node	header_node; //빈 노드
}				t_linked_list;

t_linked_list		*ft_create_linked_list();
t_linked_list_node	*ft_create_element(int degree, int coef);
int					ft_add_element_to_linked_list(t_linked_list *p_list, int position, t_linked_list_node *element);
int					ft_add_last_element_to_linked_list(t_linked_list *p_list, t_linked_list_node *element);
t_linked_list		*ft_add_linked_list_to_linked_list(t_linked_list *first, t_linked_list *second);
int					ft_remove_element_from_linked_list(t_linked_list *p_list, int position);
t_linked_list_node	*ft_get_element_from__linked_list(t_linked_list *p_list, int position);
void				ft_clear_linked_list(t_linked_list *p_list);
int					ft_get_linked_list_length(t_linked_list *p_list);
void				ft_delete_linked_list(t_linked_list *p_list);
void				ft_print_linked_list(t_linked_list *p_list);
void				ft_reverse_linked_list(t_linked_list *p_list);

#endif
```