#include "sim.h"

LinkedQueue *creatLinkedQueue() 
{ 
	LinkedQueue* pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue)); 
	memset(pReturn, 0, sizeof(LinkedQueue)); 
	return pReturn; 
}

int enQueueLQ(LinkedQueue* pQueue, int arrivalTime, int serviceTime) 
{ 
	int ret = 0; 
	LinkedQueueNode* pNode = NULL;					// pNode 생성
  LinkedQueueNode* pPreNode = NULL;
	pNode = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode)); 
	pNode->data.arrivalTime = arrivalTime;
  pNode->data.serviceTime = serviceTime;
	pNode->pLink = NULL; 
	if (isLinkedQueueEmpty(pQueue) == 0) {			// 연결 큐가 비어있지 않을때
    pPreNode = pQueue->pRear;
		pQueue->pRear->pLink = pNode; 
		pQueue->pRear = pNode;
    if (pPreNode->data.endTime < pNode->data.arrivalTime)
      pNode->data.startTime = pNode->data.arrivalTime;
    else
      pNode->data.startTime = pPreNode->data.endTime;
    pNode->data.endTime = pNode->data.serviceTime + pNode->data.startTime;
	} 
	else {											// 연결 큐가 비어있을 때 
		pQueue->pFront = pNode; 
		pQueue->pRear = pNode;
    pNode->data.startTime = pNode->data.arrivalTime;
    pNode->data.endTime = pNode->data.serviceTime + pNode->data.startTime;
	} 
	pQueue->currentCount++; 
	ret = 1; 
	return ret;										// 연결 큐에 정상적으로 자료를 추가하면 반환 값 TRUE(1)로 지정하고 반환 
}

LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue) 
{ 
	LinkedQueueNode* pReturn = NULL; 
	if (isLinkedQueueEmpty(pQueue) == 0) {			// 일반적인 디큐 
		pReturn = pQueue->pFront; 
		pQueue->pFront = pQueue->pFront->pLink; 
		pReturn->pLink = NULL; 
		pQueue->currentCount--; 
		if (isLinkedQueueEmpty(pQueue) == 1) {		// 노드가 한 개 남은 경우의 디큐 
			pQueue->pRear = NULL; 
		} 
	} 
	return pReturn; 
} 

LinkedQueueNode* peekLQ(LinkedQueue* pQueue) 
{ 
	LinkedQueueNode* pReturn = NULL; 
	if (pQueue != NULL) { 
		if (isLinkedQueueEmpty(pQueue) == 0) { 
			pReturn = pQueue->pFront; 
		} 
	} 
	return pReturn; 
}

int isLinkedQueueEmpty(LinkedQueue* pQueue) 
{ 
	int ret = 0; 
	if (pQueue != NULL) { 
		if (pQueue->currentCount == 0) { 
			ret = 1; 
		} 
	} 
	return ret; 
} 

void displayLinkedQueue(LinkedQueue* pQueue) 
{ 
	LinkedQueueNode* pNode = NULL; 
	int i = 0; 
	if (pQueue != NULL) { 
		printf("현재 노드 개수 : %d\n", 
			pQueue->currentCount); 
		pNode = pQueue->pFront; 
		while (pNode != NULL) { 
			printf("[%d]-[시작 시간 : %d][종료 시간 : %d]\n", i, pNode->data.startTime, pNode->data.endTime); 
			i++; 
			pNode = pNode->pLink; 
		} 
	} 
} 