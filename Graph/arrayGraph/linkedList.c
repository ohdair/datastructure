#include "linkedList.h"

/* 연결 리스트의 구현 */

// 리스트 생성
LinkedList* createLinkedList() {
	LinkedList* pReturn = (LinkedList*)malloc(sizeof(LinkedList));
	memset(pReturn, 0, sizeof(LinkedList)); // 할당된 메모리를 0으로 초기화
	return pReturn;
}

// 값 가져오기
int getLinkedListData(LinkedList* pList, int position) {
	int i = 0;

	ListNode* pCurrentNode = &(pList->headerNode);
	for (i = 0; i <= position; ++i) {
		pCurrentNode = pCurrentNode->pLink;
	}

	return pCurrentNode->data;
}

// 새로운 자료 추가
void addLinkedListData(LinkedList* pList, int position, int data) {
	int i = 0;
	ListNode* pNewNode = NULL;
	ListNode* pPreNode = NULL;

	pNewNode = (ListNode*)malloc(sizeof(ListNode));
	pNewNode->data = data;

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; ++i) {
		pPreNode = pPreNode->pLink;
	}

	pNewNode->pLink = pPreNode->pLink;  // 다음 노드의 처리
	pPreNode->pLink = pNewNode;         // 이전 노드의 처리
	pList->currentCount++;              // 현재 노드 개수 1 증가
}

// 기존 자료 제거
void removeLinkedListData(LinkedList* pList, int position) {
	int i = 0;
	ListNode* pDelNode = NULL;
	ListNode* pPreNode = NULL;

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; ++i) {
		pPreNode = pPreNode->pLink;
	}

	pDelNode = pPreNode->pLink;
	pPreNode->pLink = pDelNode->pLink;
	free(pDelNode);
	pList->currentCount--;
}

// 기타 연산자(while문의 블록을 실행하면서, 각각의 노드에 대해서 메모리를 해제하고 연결리스트 자체의 메모리를 해제
void deleteLinkedList(LinkedList* pList) {
	ListNode* pDelNode = NULL;
	ListNode* pPreNode = pList->headerNode.pLink;
	while (pPreNode != NULL) {
		pDelNode = pPreNode;
		pPreNode = pPreNode->pLink;

		free(pDelNode); // 연결리스트 자체를 메모리 해제
	}
	free(pList);
}

int getLinkedListLength(LinkedList* pList) {
	if (NULL != pList) {
		return pList->currentCount;
	}
	return 0;
}
