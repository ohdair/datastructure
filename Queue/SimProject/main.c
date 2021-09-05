#include "sim.h"

int main() {
  LinkedQueue *pQueue = NULL;
  LinkedQueueNode *pNode = NULL;

  pQueue = creatLinkedQueue();
  if (pQueue != NULL) {
    enQueueLQ(pQueue, 0, 3);
    enQueueLQ(pQueue, 2, 2);
    enQueueLQ(pQueue, 4, 1);
    enQueueLQ(pQueue, 6, 1);
    enQueueLQ(pQueue, 8, 3);
  }
  displayLinkedQueue(pQueue);
  
  return 0;
}