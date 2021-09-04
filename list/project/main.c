#include "project.h"

int	main()
{
	t_linked_list	*list1;
  t_linked_list *list2;
  t_linked_list *new_list;

	list1 = ft_create_linked_list(); // 헤더노드 생성
	list2 = ft_create_linked_list();
	for (int i = 3; i > -1; i--)
	{
		t_linked_list_node *node1 = ft_create_element(2 * i, i + 1);
		ft_add_last_element_to_linked_list(list1, node1);
	}
	for (int i = 4; i > -1; i--)
  {  
		t_linked_list_node *node2 = ft_create_element(2 * i, 2 * i);
		ft_add_last_element_to_linked_list(list2, node2);    
  }
	printf("\n--------list 1-------\n\n");  
  ft_print_linked_list(list1); //리스트 출력
	printf("\n--------list 2-------\n\n");  
	ft_print_linked_list(list2); //리스트 출력
	// ft_reverse_linked_list(list); //리스트 역순
	printf("\n--------after add-------\n\n");
	// ft_print_linked_list(list); //리스트 출력
  new_list = ft_add_linked_list_to_linked_list(list1, list2);
	ft_print_linked_list(new_list); //리스트 출력




}