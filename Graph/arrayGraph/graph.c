#include "graph.h"


DirectLinkedGraph* createDirectLinkedGraph(int nodeCount) // 그래프의 생성
{
	int i = 0;
	DirectLinkedGraph* pReturn = NULL;
	if (nodeCount > 0) {
		pReturn = (DirectLinkedGraph*)malloc(sizeof( DirectLinkedGraph));
		if (pReturn == NULL) {
			printf("오류, 메모리 할당(1), in createLinkedGraph()\n");
			return NULL;
		}
		pReturn->nodeCount = nodeCount;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야합니다\n");
		return NULL;
	}
	pReturn->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList*) * nodeCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리 할당(3), in createLinkedGraph()\n");
		if (pReturn != NULL)
			free(pReturn);
		return NULL;
	}
	for (i = 0; i < nodeCount; ++i) {
		pReturn->ppAdjEdge[i] = createLinkedList();
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리 할당(4), in createLinkedGraph()\n");
			if (pReturn->ppAdjEdge != NULL)
				free(pReturn->ppAdjEdge);
			if (pReturn != NULL)
				free(pReturn);
			return NULL;
		}
	}
	return pReturn;
}

int checkVertexValid(DirectLinkedGraph* pGraph, int node)
{
	if (pGraph != NULL && node >= 0 && node < pGraph->nodeCount)
		return 1;
	else
		return 0;
}

int addEdgeDLG(DirectLinkedGraph* pGraph, int fromNode, int toNode) // 간선의 추가
{
	int ret = 0;
	if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode))
		addLinkedListData(pGraph->ppAdjEdge[fromNode], 0, toNode);
	else
		ret = -1;
	return ret;
}

int removeEdgeDLG(DirectLinkedGraph* pGraph, int fromNode, int toNode)
{
	int ret = -1;
	LinkedList* pList = NULL;
	int i = 0, count = 0;
	if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
		pList = pGraph->ppAdjEdge[fromNode];
		count = getLinkedListLength(pList);
		for (i = 0; i < count; i++) {
			if (getLinkedListData(pList, 1) == toNode) {
				removeLinkedListData(pList, i);
				ret = 0;
				break;
			}
		}
	}
	else
		ret = -1;
	return ret;
}

int getEdgeDLG(DirectLinkedGraph* pGraph, int fromNode, int toNode)
{
	int ret = 0;
	LinkedList* pList = NULL;
	int i = 0, count = 0;
	if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
		pList = pGraph->ppAdjEdge[fromNode];
		count = getLinkedListLength(pList);
		for (i = 0; i < count; i++) {
			if (getLinkedListData(pList, 1) == toNode) {
			ret = 1;
			break;
			}
		}
	}
	return ret;
}

void displayGraphDLG(DirectLinkedGraph* pGraph)
{
	int i = 0, j = 0, count = 0;
	if (pGraph != NULL) {
		count = pGraph->nodeCount;
		for (i = 0; i < count; i++) {
			for (j = 0; j < count; j++) {
				if (getEdgeDLG(pGraph, i, j)) {
					printf("1 ");
				}
				else
				printf("0 ");
			}
			printf("\n");
		}
	}
}

void deleteGraphDLG(DirectLinkedGraph* pGraph)
{
	int i = 0;
	if (pGraph != NULL) {
		for (i = 0; i < pGraph->nodeCount; i++) {
			deleteLinkedList(pGraph->ppAdjEdge[i]);
		}
		if (pGraph->ppAdjEdge != NULL)
			free(pGraph->ppAdjEdge);
		free(pGraph);
	}
}
