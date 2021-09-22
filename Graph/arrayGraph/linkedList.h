#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNodeType {
int data;
struct LinkedListNodeType* pLink;
} ListNode;

typedef struct LinkedListType {
int currentCount;
ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
int getLinkedListData(LinkedList* pList, int position);
void addLinkedListData(LinkedList* pList, int position, int data);
void removeLinkedListData(LinkedList* pList, int position);
void deleteLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
