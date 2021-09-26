#include "../linkedGraph/graph.h"
#include "../../Stack/stack.h"

void traversal_DFS(LinkedGraph *pGraph){
    Stack *s = NULL;
    ListNode *u = NULL;
    
    s = init();
    pGraph->pVertex[0] = USED;
    u = &pGraph->ppAdjEdge[0]->headerNode;
    ft_push(s, 0);
    while (s){
        pop(u);
        for(){
            
        }
    }
}