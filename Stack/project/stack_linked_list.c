#include "linked_list.h"

void ft_push(t_linked_list *pList, t_coordinate point){
  t_linked_list_node *new_node = NULL;
  new_node = ft_create_element(point);
  if (!new_node)
  {
    printf("Error! Wrong malloc\n");
    return ;
  }
  if (pList->header_node->next == NULL)
    pList->header_node->next = new_node;
  else
  {
    new_node->next = pList->header_node->next;
    pList->header_node->next = new_node;
  }
  pList->num_of_current_element++;
}

void ft_pop(t_linked_list *pList){
  t_linked_list_node *tmp_node = NULL;
  if (pList->header_node->next == NULL)
  {
    printf("Error! Underflow\n");
    return ;
  }
  tmp_node = pList->header_node->next;
  pList->header_node->next = pList->header_node->next->next;
  tmp_node->next = NULL;
  free(tmp_node);
  pList->num_of_current_element--;
}

t_linked_list_node *ft_peek(t_linked_list *pList){
  return (pList->header_node->next);
}