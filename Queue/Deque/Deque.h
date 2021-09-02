#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

# define  TRUE  1
# define  FALSE 0

typedef struct DequeNodeType { 
    int data; 
    struct DequeNodeType *pLLink; 
    struct DequeNodeType *pRLink;
} DequeNode;

typedef struct DequeType {
    int currentCount; 
    DequeNode *pFrontNode;
    DequeNode *pRearNode;
} Deque;

Deque     *createDeque(void);
DequeNode *createNode(int data);
int       deleteDeque(Deque *pList);
int       insertFront(Deque *pList, int data);
int       deleteFront(Deque *pList);
int       insertRear(Deque *pList, int data);
int       deleteRear(Deque *pList);
void      displayDeque(Deque *pList);