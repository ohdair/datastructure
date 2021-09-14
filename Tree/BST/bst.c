#include "bst.h"
#include <unistd.h>

#define TRUE 1
#define FALSE 0

BinSearchTree* createBinSearchTree()
{
  BinSearchTree *ret = (BinSearchTree*)malloc(sizeof(BinSearchTree));
  if (ret == NULL)
    return NULL;
  ret->pRootNode = NULL;
  return ret;
}

BinSearchTreeNode *createBinSearchNode(int key, char value)
{
  BinSearchTreeNode *result;

  result = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
  if (result == NULL)
    return NULL;
  result->key = key;
  result->value = value;
  result->pLeftChild = NULL;
  result->pRightChild = NULL;
  return result;
}
// 검색
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
  // 검색의 시작은 루트노드부터
  BinSearchTreeNode *result = pBinSearchTree->pRootNode;

  while(result != NULL) {
    if (key == result->key) {
      break;
    }
    else if (key < result->key) {
      result = result->pLeftChild;
    }
    else {
      result = result->pRightChild;
    }
  }
  return result;
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode* element)
{
  BinSearchTreeNode *p = pBinSearchTree->pRootNode;
  // 루트 노드가 비어있는지 확인, 없으면 루트에 element
  // 있으면 자식노드랑 비교 후 교체
  // 없을 때까지 반복
  if (searchBST(pBinSearchTree, element->key) != NULL) //중복되는 값이 있을때.
    return FALSE;
  //루트가 비어있으면 element는 루트노드
  if (pBinSearchTree->pRootNode == NULL)
  {
    pBinSearchTree->pRootNode = element;
    return TRUE;
  }
  while(TRUE)
  {
    // if (p == NULL)
    // {
    //   p = element;
    //   return TRUE;
    // }
    if (p->key > element->key)
    {
		  if (p->pLeftChild == NULL)
		  {
		  	p->pLeftChild = element;
		  	return TRUE;
		  }
      p = p->pLeftChild;
    }
    else
    {
		  if (p->pRightChild == NULL)
		  {
		  	p->pRightChild = element;
		  	return TRUE;
		  }
      p = p->pRightChild;
    }
  }
  return TRUE; //성공 1 실패 0
}

static BinSearchTreeNode* getParentsNode(BinSearchTree* pBinSearchTree, BinSearchTreeNode* pDelNode)
{
  BinSearchTreeNode *result = pBinSearchTree->pRootNode;

  while(result != NULL) {
    if (pDelNode == result->pLeftChild || pDelNode == result->pRightChild){
      break;
    }
    else if (pDelNode->key < result->key) {
      result = result->pLeftChild;
    }
    else 
      result = result->pRightChild;
  }
    return result;
}

BinSearchTreeNode *getpSuccessor(BinSearchTreeNode *pDelNode)
{
  BinSearchTreeNode *result;

  result = pDelNode->pRightChild;
  while (result->pLeftChild != NULL)
  {
    result = result->pLeftChild;
  }
  return (result);
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
  BinSearchTreeNode *pDelNode; //삭제할 노드
  BinSearchTreeNode *pParentNode; //삭제할 노드의 부모녿
  BinSearchTreeNode *pPredecessor;  //대체노드의 부모노드
  BinSearchTreeNode *pSuccessor; //대체할 노드


  /*
    삭제할 노드의 부모노드를 아는 방법.
    삭제할 노드가 몇개의 자식노드를 가지는지 어떻게 알수있나..
  */
  pDelNode = searchBST(pBinSearchTree, key);
  if (pDelNode == NULL)
  {
    write(1, "NOT FOUND\n", 10);
    return FALSE;
  }
  pParentNode = getParentsNode(pBinSearchTree, pDelNode);
  //단말노드
  if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL)
  {
    //부모노드와 삭제할 노드의 관계를 끊어줘야한다.
    if (pParentNode->pLeftChild == pDelNode)
      pParentNode->pLeftChild = NULL;
    else
      pParentNode->pRightChild = NULL;
    pDelNode = NULL;
    free(pDelNode);
    return TRUE;
  }
  //자식노드 1 개 왼쪽이 존제
  else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild == NULL)
  {
    if (pParentNode->pLeftChild == pDelNode)
      pParentNode->pLeftChild = pDelNode->pLeftChild;
    else
      pParentNode->pRightChild = pDelNode->pLeftChild;
    pDelNode = NULL;
    free(pDelNode);
    return TRUE;
  }
  //자식노드 1 개 오른쪽 존제
  else if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild != NULL)
  {
    if (pParentNode->pLeftChild == pDelNode)
      pParentNode->pLeftChild = pDelNode->pRightChild;
    else
      pParentNode->pRightChild = pDelNode->pRightChild;
    pDelNode = NULL;
    free(pDelNode);
    return TRUE;
  }

  //자식노드 2 개
  else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL)
  {
    pSuccessor = getpSuccessor(pDelNode);
    pDelNode->key = pSuccessor->key;
    pDelNode->value = pSuccessor->value;
    pPredecessor = getParentsNode(pBinSearchTree, pSuccessor);
    if (pSuccessor->pRightChild == NULL)
      pPredecessor->pLeftChild = NULL;
    else
      pPredecessor->pLeftChild = pSuccessor->pRightChild;
    pSuccessor = NULL;
    free(pSuccessor);
  }
  return TRUE; //성공 1 실패 0
}


void InOrderBinTree(BinSearchTree *pBinSearchTree)
{
  if (pBinSearchTree != NULL)
  {
    InOrderBinTreeNode(pBinSearchTree->pRootNode);
  }
}

void InOrderBinTreeNode(BinSearchTreeNode *element)
{
  if (element == NULL)
    return ;
  InOrderBinTreeNode(element->pLeftChild);
  printf("[%d %c] -> ", element->key, element->value);
  InOrderBinTreeNode(element->pRightChild);
}
