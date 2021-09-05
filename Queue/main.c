#include "queue.h"

int main(int argc, char* argv[]) 
{ 
	LinkedQueue* pQueue = NULL; 
	LinkedQueueNode* pNode = NULL; 
	//배열 큐 생성 
	pQueue = creatLinkedQueue(); 
	if (pQueue != NULL) { 
	// 큐 초기화: 'A' ~ 'D' 추가 
		enQueueLQ(pQueue, 'A'); 
		enQueueLQ(pQueue, 'B'); 
		enQueueLQ(pQueue, 'C'); 
		enQueueLQ(pQueue, 'D'); 
		displayLinkedQueue(pQueue); 
		pNode = dequeueLQ(pQueue); 
		if (pNode != NULL) { 
			printf("Dequeue Value-[%c]\n", pNode->data); 
			free(pNode); 
		} 
		displayLinkedQueue(pQueue); 
		pNode = peekLQ(pQueue); 
		if (pNode != NULL) { 
			printf("Peek Value-[%c]\n", pNode->data); 
		} 
		displayLinkedQueue(pQueue); 
		//큐에 E 추가 
		enQueueLQ(pQueue, 'E'); 
		displayLinkedQueue(pQueue); 
	} 
	return 0; 
}