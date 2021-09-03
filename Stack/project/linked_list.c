
#include "linked_list.h"

void	ft_reverse_linked_list(t_linked_list *p_list)
{
	t_linked_list_node 		*origin;
	t_linked_list_node		*curr;

	if (p_list->num_of_current_element <= 1)
		return ;
	curr = p_list->header_node->next; 
	origin = curr->next;
	curr->next = NULL; 
	while (origin != NULL)
	{
		curr = origin;
		origin = origin->next;
		curr->next = p_list->header_node->next;
		p_list->header_node->next = curr;
	}
	return ;
}

t_linked_list	*ft_create_linked_list()
{
	t_linked_list	*list;
  t_coordinate point;

  point.x = 0;
  point.y = 0;
	list = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (list == NULL)
		return (NULL);
	list->header_node = ft_create_element(point);
	list->num_of_current_element = 0;
	return (list);
}

int	ft_add_element_to_linked_list(t_linked_list *p_list, int position, t_linked_list_node *element)
{
	t_linked_list_node *curr;

	curr = p_list->header_node;
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

  	if (p_list->header_node->next == NULL)
  	{  
   		p_list->header_node->next = element;
   		++p_list->num_of_current_element;
    return (0);
  	}
  	curr = p_list->header_node->next;
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
	
	curr = p_list->header_node->next;
	int i = 0;
  printf("시작 -> ");
	while (curr)
	{
		printf("(%d, %d) -> ", curr->point.x, curr->point.y);
		++i;
		curr = curr->next;
	}
  printf("탈출\n");
	return ;
}

t_linked_list_node	*ft_create_element(t_coordinate point)
{
	t_linked_list_node *new_element;
	
	new_element = (t_linked_list_node *)malloc(sizeof(t_linked_list_node));
	if (new_element == NULL)
		return (NULL);
	new_element->point = point;
	new_element->next = NULL;
	return (new_element);
}

int	ft_remove_element_from_linked_list(t_linked_list *p_list, int position)
{
	int					idx;
	t_linked_list_node	*curr;
	t_linked_list_node	*tmp;

	if (position >= p_list->num_of_current_element)
		return (-1);
	idx = 0;
	curr = p_list->header_node;
	while (curr)
	{
		if (idx == position)
		{
			tmp = curr->next;
			curr->next = curr->next->next;
			free(tmp);
			--p_list->num_of_current_element;
			return (0);
		}
		++idx;
		curr = curr->next;
	}
	return (0);
}

t_linked_list_node	*ft_get_element_from__linked_list(t_linked_list *p_list, int position)
{
	int					idx;
	t_linked_list_node	*curr;

	idx = 0;
	curr = p_list->header_node->next;
	while (curr)
	{
		if (idx == position)
		{
			return (curr);
		}
		++idx;
		curr = curr->next;
	}
	return (NULL);
}

void	ft_clear_linked_list(t_linked_list *p_list)
{
	t_linked_list_node	*curr;
	t_coordinate point;

  point.x = 0;
  point.y = 0;
	curr = p_list->header_node->next;
	while (curr)
	{
		curr->point = point;
		curr = curr->next;
	}
	p_list->num_of_current_element = 0;
	return ;
}

void	ft_delete_linked_list(t_linked_list *p_list)
{
	t_linked_list_node *curr;
	t_linked_list_node *tmp;

	curr = p_list->header_node;
	tmp = curr;
	while (curr)
	{
		curr = curr->next;
		free(tmp);
		tmp = curr;
	}
	p_list->header_node->next = NULL;
	p_list->num_of_current_element = 0;
	return ;
}
