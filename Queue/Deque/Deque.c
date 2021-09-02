#include "Deque.h"

Deque *createDeque(void) { 
  Deque *pReturn = (Deque *)malloc(sizeof(Deque)); 
  if(pReturn != NULL)
    memset(pReturn, 0, sizeof(Deque)); 
  pReturn->pFrontNode = createNode(0);
  pReturn->pRearNode = createNode(0);
  return pReturn; 
}

DequeNode *createNode(int data) {
  DequeNode *ret = (DequeNode *)malloc(sizeof(DequeNode));
  if (ret != NULL)
    memset(ret, 0, sizeof(DequeNode));
  else {
    printf("ERROR give me the memory\n");
    return NULL;
  }
  ret->data = data;
  return ret;
}

int   deleteDeque(Deque *pList) {
  if (!pList)
  {
    printf("Deque does not exist\n");
    return FALSE;
  }

  while (pList->currentCount) {
    deleteFront(pList);
  }
  free(pList);
}

int insertFront(Deque *pList, int data) {
  DequeNode *newNode = createNode(data);

  if (!pList)
  {
    printf("Deque does not exist\n");
    return FALSE;
  }
  if (!newNode)
    return FALSE;

  if (!pList->currentCount) {
    pList->pFrontNode->pLLink = newNode;
    pList->pRearNode->pRLink = newNode;
  }
  else {
    newNode->pRLink = pList->pFrontNode->pLLink;
    pList->pFrontNode->pLLink->pLLink = newNode;
    pList->pFrontNode->pLLink = newNode;
  }
  pList->currentCount++;
}

int deleteFront(Deque *pList) {
  DequeNode *preNode;
  DequeNode *delNode;

  delNode = pList->pFrontNode->pLLink;
  if (!pList->currentCount)
    return FALSE;
  else if (pList->currentCount == 1) {
    pList->pFrontNode->pLLink = NULL;
    pList->pRearNode->pRLink = NULL;
  }
  else {
    preNode = delNode->pRLink;
    pList->pFrontNode->pLLink = preNode;
    delNode->pRLink = NULL;
  }
  free(delNode);
  pList->currentCount--;
  return TRUE;
}

int insertRear(Deque *pList, int data) {
  DequeNode *newNode = createNode(data);

  if (!pList)
  {
    printf("Deque does not exist\n");
    return FALSE;
  }
  if (!newNode) {
    return FALSE;
  }
  if (!pList->currentCount) {
    pList->pFrontNode->pLLink = newNode;
    pList->pRearNode->pRLink = newNode;
  }
  else {
    newNode->pLLink = pList->pRearNode->pRLink;
    pList->pRearNode->pRLink->pRLink = newNode;
    pList->pRearNode->pRLink = newNode;
  }
  pList->currentCount++;
}

int deleteRear(Deque *pList) {
  DequeNode *preNode;
  DequeNode *delNode;

  delNode = pList->pRearNode->pRLink;
  if (!pList->currentCount)
    return FALSE;
  else if (pList->currentCount == 1) {
    pList->pFrontNode->pLLink = NULL;
    pList->pRearNode->pRLink = NULL;
  }
  else {
    preNode = delNode->pLLink;
    pList->pRearNode->pRLink = preNode;
    delNode->pLLink = NULL;
    preNode->pRLink = NULL;
  }
  free(delNode);
  pList->currentCount--;
  return TRUE;
}

void  displayDeque(Deque *pList) {
  DequeNode *current;

  if (!pList)
  {
    printf("Deque does not exist\n");
    return ;
  }
  if (!pList->currentCount)
    return;
  current = pList->pFrontNode->pLLink;
  while(current)
  {
    printf("%d->", current->data);
    current = current->pRLink;
  }
  printf("\n");
}