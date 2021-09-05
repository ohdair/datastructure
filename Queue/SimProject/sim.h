#ifndef SIM_H
# define SIM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum SimStatusType {
  arrival, start, end
} SimStatus;

typedef struct SimCustomerType
{
  SimStatus status;
  int arrivalTime;
  int serviceTime;
  int startTime; 
  int endTime;  //종료시각 : 시작시각 + 서비스 시간.
} SimCustomer;

typedef struct LinkedQueueNodeType 
{ 
	SimCustomer data;
	struct LinkedQueueNodeType* pLink; 
} LinkedQueueNode; 

typedef struct LinkedQueueType 
{ 
	int currentCount; // 현재 손님 수
	LinkedQueueNode* pFront;
	LinkedQueueNode* pRear;
} LinkedQueue;

LinkedQueue* creatLinkedQueue();
int enQueueLQ(LinkedQueue* pQueue, int arrivalTime, int serviceTime);
LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue);
LinkedQueueNode* peekLQ(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);
void displayLinkedQueue(LinkedQueue* pQueue);

#endif