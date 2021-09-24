#include "graph.h"

// 무방향 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount){
	LinkedGraph* ret = NULL;
	if (maxVertexCount > 0){
		ret = (LinkedGraph*)malloc(sizeof(LinkedGraph));
		if (ret == NULL)
		{
			printf("ERROR!! Creation failed\n");
			return NULL;
		}
		ret->graphType = GRAPH_UNDIRECTED;	// 무방향
		ret->maxVertexCount = maxVertexCount;
	}
	else{
		printf("ERROR!! maxVertexCount must be greater than 0\n");
		return NULL;
	}

	ret->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);	// 노드의 사용여부 배열 메모리
	if (ret->pVertex == NULL) {
		printf("ERROR!! Creation failed\n");
		return NULL;
	}
	memset(ret->pVertex, NOT_USED, sizeof(int) * maxVertexCount);

	ret->ppAdjEdge = (int**)malloc(sizeof(int*) * maxVertexCount);	// 간선을 저장하는 배열 메모리 할당
	if (ret->ppAdjEdge == NULL) {
		printf("ERROR!! Creation failed\n");
		return NULL;
	}
	for (int i = 0; i < maxVertexCount; ++i){
		ret->ppAdjEdge[i] = (int*)malloc(sizeof(int) * maxVertexCount);
		if (ret->ppAdjEdge == NULL) {
			printf("ERROR!! Creation failed\n");
			return NULL;
		}
	}
	for (int i = 0; i < maxVertexCount; ++i){
		memset(ret->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
	}
	return ret;
}

// 방향 그래프 생성
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount){
	LinkedGraph* ret = NULL;
	ret = createLinkedGraph(maxVertexCount);
	ret->graphType = GRAPH_DIRECTED;	// 방향 그래프
	return ret;
}

void deleteLinkedGraph(LinkedGraph* pGraph){
	if (pGraph != NULL){
		free(pGraph->pVertex);
		for (int i = 0; i < pGraph->maxVertexCount; ++i){
			free(pGraph->ppAdjEdge[i]);
		}
		free(pGraph->ppAdjEdge);
		free(pGraph);
	}
}

int isEmptyLG(LinkedGraph* pGraph) {
	if (pGraph != NULL)
		return TRUE;
	return FALSE;
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID){
	int ret = SUCCESS;

	if (isEmptyLG(pGraph)){
		if (vertexID < pGraph->maxVertexCount && pGraph->pVertex[vertexID] == NOT_USED){
			pGraph->pVertex[vertexID] == USED;
			pGraph->currentVertexCount++;
		}
		else {
			printf("ERROR!! Either the node exists or the number of nodes has been exceeded\n");
			ret = FAIL;
		}
	}
	return ret;
}

// 간선 추가
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight){
	int ret = SUCCESS;

	if (isEmptyLG(pGraph)){
		if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED){	// 노드가 있는 지 여부
			if (getLinkedListData(pGraph->ppAdjEdge[fromVertexID], toVertexID) == 0){	// 이미 사용중인 간선인지 체크
				addLinkedListData(pGraph->ppAdjEdge[fromVertexID], toVertexID, weight);
				pGraph->currentEdgeCount++;
				if (pGraph->graphType == GRAPH_UNDIRECTED) {	// 무방향 그래프, 반대편 추가
					addLinkedListData(pGraph->ppAdjEdge[toVertexID], fromVertexID, weight);
				}
				else {
					printf("ERROR!! The Edge already exists\n");
					ret = FAIL;
				}
			}
			else{
				printf("ERROR!! The Node does not exist\n");
				ret = FAIL;
			}
		}
	}
	return ret;
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
	return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID) {
	if (pGraph->pVertex[vertexID] == USED)
		return TRUE;
	return FALSE;
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID){
	int ret = SUCCESS;

	if (isEmptyLG(pGraph)){
		if (checkVertexValid(pGraph, vertexID)){
			for (int i = 0; i < pGraph->maxVertexCount; ++i){
				removeLinkedListData(pGraph->ppAdjEdge[vertexID], i);
				removeLinkedListData(pGraph->ppAdjEdge[i], vertexID);
			}
			pGraph->pVertex == NOT_USED;
			pGraph->currentVertexCount--;
		}
		else{
			printf("ERROR!! The Node does not exist\n");
			ret = FAIL;
		}
	}
	return ret;
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
	int ret = SUCCESS;

	if (isEmptyLG(pGraph)){
		if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID)){
			if (getLinkedListData(pGraph->ppAdjEdge[fromVertexID], toVertexID) != 0) {
				removeLinkedListData(pGraph->ppAdjEdge[fromVertexID], toVertexID);
				if (pGraph->graphType == GRAPH_UNDIRECTED) {
					removeLinkedListData(pGraph->ppAdjEdge[toVertexID], fromVertexID);
				}
			}
			else {
				printf("ERROR!! The Edge already exists\n");
				ret = FAIL;
			}
		}
		else {
			printf("ERROR!! The Node does not exist\n");
			ret = FAIL;
		}
	}
	return ret;
}

void deleteGraphNode(LinkedList* pList, int delVertexID){	// 연결된 곳에서 노드 삭제
	if (findGraphNodePosition(pList, delVertexID))
		removeLinkedListData(pList, delVertexID);
}

int findGraphNodePosition(LinkedList* pList, int vertexID){	// vertex 존재 유무
	ListNode *cur = NULL;
	cur = &pList->headerNode;
	while(cur)
	{
		if (cur->data == vertexID)
			return TRUE;
		cur = cur->pLink;
	}
	return FALSE;
}

int getEdgeCountLG(LinkedGraph* pGraph){
	return pGraph->currentEdgeCount;
}

int getVertexCountLG(LinkedGraph* pGraph){
	return pGraph->currentVertexCount;
}

int getMaxVertexCountLG(LinkedGraph* pGraph){
	return pGraph->maxVertexCount;
}

int getGraphTypeLG(LinkedGraph* pGraph){
	return pGraph->graphType;
}

void displayLinkedGraph(LinkedGraph* pGraph){
	printf("vertex size : %d\n", getVertexCountLG(pGraph));

}
