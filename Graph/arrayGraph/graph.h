#ifndef _GRAPH_H_
# define _GRAPH_H_

#include "linkedList.h"

typedef struct DirectLinkedGraphType
{
	int nodeCount;
	LinkedList** ppAdjEdge;
} DirectLinkedGraph;

DirectLinkedGraph* createDirectLinkedGraph(int nodeCount);
int checkVertexValid(DirectLinkedGraph* pGraph, int node);
int addEdgeDLG(DirectLinkedGraph* pGraph, int fromNode, int toNode); // 간선의 추가
int removeEdgeDLG(DirectLinkedGraph* pGraph, int fromNode, int toNode);
int getEdgeDLG(DirectLinkedGraph* pGraph, int fromNode, int toNode);
void displayGraphDLG(DirectLinkedGraph* pGraph);
void deleteGraphDLG(DirectLinkedGraph* pGraph);

#endif
