#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct  s_coordinate
{
  int x;
  int y;
} t_coordinate;

typedef struct	s_linked_list_node
{
	t_coordinate point;
  char         direction;
	struct s_linked_list_node	*next;
}				t_linked_list_node;

typedef struct	s_linked_list
{
	int					num_of_current_element;
	t_linked_list_node	*header_node; //빈 노드
}				t_linked_list;

/*
** linked_list.c
*/
t_linked_list		*ft_create_linked_list();
t_linked_list_node	*ft_create_element(t_coordinate point);
int					ft_add_element_to_linked_list(t_linked_list *p_list, int position, t_linked_list_node *element);
int					ft_add_last_element_to_linked_list(t_linked_list *p_list, t_linked_list_node *element);
int					ft_remove_element_from_linked_list(t_linked_list *p_list, int position);
t_linked_list_node	*ft_get_element_from__linked_list(t_linked_list *p_list, int position);
void				ft_clear_linked_list(t_linked_list *p_list);
// int					ft_get_linked_list_length(t_linked_list *p_list);
void				ft_delete_linked_list(t_linked_list *p_list);
void				ft_print_linked_list(t_linked_list *p_list);
void				ft_reverse_linked_list(t_linked_list *p_list);

/*
** stack_linked.c
*/
t_linked_list_node *ft_peek(t_linked_list *pList);
void ft_pop(t_linked_list *pList);
void ft_push(t_linked_list *pList, t_coordinate point);

/*
** check_bracket.c
*/
int check_bracket_matching(t_linked_list *pList);

#endif