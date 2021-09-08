// 다항식 구현
#include "project.h"

void	ft_reverse_linked_list(t_linked_list *p_list)
{
	t_linked_list_node 		*origin;
	t_linked_list_node		*curr;

	if (p_list->num_of_current_element <= 1)
		return ;
	curr = p_list->header_node.next; 
	origin = curr->next;
	curr->next = NULL; 
	while (origin != NULL)
	{
		curr = origin;
		origin = origin->next;
		curr->next = p_list->header_node.next;
		p_list->header_node.next = curr;
	}
	return ;
}

t_linked_list	*ft_create_linked_list()
{
	t_linked_list	*list;

	list = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (list == NULL)
		return (NULL);
	list->header_node.next = NULL;
	list->header_node.coef = 0;
	list->header_node.degree = 0;
	list->num_of_current_element = 0;
	return (list);
}

int	ft_add_element_to_linked_list(t_linked_list *p_list, int position, t_linked_list_node *element)
{
	t_linked_list_node *curr;

	curr = &(p_list->header_node);
	int cnt = 0;
	while (curr)
	{
		if (cnt == position)
		{
			element->next = curr->next;
			curr->next = element;
			++p_list->num_of_current_element;
			return (0);
		}
		++cnt;
		curr = curr->next;
	}
	return (0);
}

int	ft_add_last_element_to_linked_list(t_linked_list *p_list, t_linked_list_node *element)
{
	t_linked_list_node *curr;

  if (p_list->header_node.next == NULL)
  {  
    p_list->header_node.next = element;
    ++p_list->num_of_current_element;
    return (0);
  }
  curr = p_list->header_node.next;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
  ++p_list->num_of_current_element;
	curr->next = element;
	return (0);
}

void	ft_print_linked_list(t_linked_list *p_list)
{
	t_linked_list_node *curr;
	
	curr = p_list->header_node.next;
	int i = 0;
	while (curr)
	{
		printf("node[%d] -> coef: %d, degree: %d\n", i, curr->coef, curr->degree);
		++i;
		curr = curr->next;
	}
	return ;
}

t_linked_list		*ft_add_linked_list_to_linked_list(t_linked_list *first, t_linked_list *second)
{
	t_linked_list *new_list = ft_create_linked_list();
	t_linked_list_node *curr_first = first->header_node.next;
	t_linked_list_node *curr_second = second->header_node.next;

	while (curr_first || curr_second)
	{
		if (!curr_second || curr_first->degree > curr_second->degree)
		{
		  t_linked_list_node *node = ft_create_element(curr_first->degree, curr_first->coef);
			ft_add_last_element_to_linked_list(new_list, node);
			curr_first = curr_first->next;
		}
		else if (!curr_first || curr_second->degree > curr_first->degree)
		{
			t_linked_list_node *node = ft_create_element(curr_second->degree, curr_second->coef);
			ft_add_last_element_to_linked_list(new_list, node);
			curr_second = curr_second->next;
		}
		else
		{
      t_linked_list_node *node = ft_create_element(curr_first->degree, curr_first->coef + curr_second->coef);
			ft_add_last_element_to_linked_list(new_list, node);
			curr_first = curr_first->next;
			curr_second = curr_second->next;
		}
	}
  return (new_list);
}

t_linked_list_node	*ft_create_element(int degree, int coef)
{
	t_linked_list_node *new_element;
	
	new_element = (t_linked_list_node *)malloc(sizeof(t_linked_list_node));
	if (new_element == NULL)
		return (NULL);
	new_element->degree = degree;
	new_element->coef = coef;
	new_element->next = NULL;
	return (new_element);
}