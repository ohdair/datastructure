#include <stdio.h>
#include "Deque.h"

int main(void) 
{ 
	Deque		*pList;

// Create
	printf("\n----------------CREATE----------------\n");
	pList = createDeque();
	displayDeque(pList);

//	Insert Front
	printf("\n---------------Insert Front-------------\n");
	insertFront(pList, 1);

	displayDeque(pList);
	printf("\n");

	insertFront(pList, 2);
	displayDeque(pList);
	printf("\n");

	insertFront(pList, 3);
	displayDeque(pList);
	printf("\n");

//	Insert Rear
	printf("\n---------------Insert Rear-------------\n");
	insertRear(pList, 4);
	displayDeque(pList);
	printf("\n");

	insertRear(pList, 5);
	displayDeque(pList);
	printf("\n");

	insertRear(pList, 6);
  displayDeque(pList);
	printf("\n");

//	Delete Front
	printf("\n---------------Delete Front-------------\n");
	if (deleteFront(pList))
  	printf("Delete Front\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");
	
	if (deleteFront(pList))
  	printf("Delete Front\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");

	if (deleteFront(pList))
  	printf("Delete Front\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");
  

//	Delete Rear
	printf("\n---------------Delete Rear-------------\n");
	if (deleteRear(pList))
  	printf("Delete Rear\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");

	if (deleteRear(pList))
  	printf("Delete Rear\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");

	if (deleteRear(pList))
  	printf("Delete Rear\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");

  // empty
	if (deleteRear(pList))
  	printf("Delete Rear\n");
  else
    printf("Deque is empty!\n");
	displayDeque(pList);
	printf("\n");

// Delete Deque
	printf("\n---------------Delete Deque-------------\n");
	deleteDeque(pList);
	displayDeque(pList);
	printf("\n");

	// while(1);
	return (0);
}