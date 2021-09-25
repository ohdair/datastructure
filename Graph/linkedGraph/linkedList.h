#ifndef _LINKEDLIST_
# define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNodeType {
int data;
int nodeNumber;
struct LinkedListNodeType* pLink;
} ListNode;

typedef struct LinkedListType {
int currentCount;
ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
int getLinkedListData(LinkedList* pList, int nodeNumber);
void addLinkedListData(LinkedList* pList, int nodeNumber, int data);
void removeLinkedListData(LinkedList* pList, int nodeNumber);
void deleteLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);

#endif
