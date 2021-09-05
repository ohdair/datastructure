#ifndef QUEUE_H
# define QUEUE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct LinkedQueueNodeType 
{ 
	char data;
	struct LinkedQueueNodeType* pLink; 
} LinkedQueueNode; 

typedef struct LinkedQueueType 
{ 
	int currentCount; // 현재 손님 수
	LinkedQueueNode* pFront;
	LinkedQueueNode* pRear;
} LinkedQueue;

LinkedQueue *creatLinkedQueue();
int enQueueLQ(LinkedQueue *pQueue, char data);
LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue);
LinkedQueueNode *peekLQ(LinkedQueue *pQueue);
void deleteLinkedQueue(LinkedQueue *pQueue);
int isLinkedQueueEmpty(LinkedQueue *pQueue);
void displayLinkedQueue(LinkedQueue *pQueue);

#endif