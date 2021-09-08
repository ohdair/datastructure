#include "BinTree.h"
#include "BinTreeTraversal.h"

void PreOrderBinTree(BinTree *pBinTree)
{
  if (pBinTree != NULL)
  {
    PreOrderBinTreeNode(pBinTree->pRootNode);
  }
}

void PreOrderBinTreeNode(BinTreeNode* pRootNode)
{
  if (pRootNode != NULL)
  {
    pRootNode->visited = TRUE;
    printf("%c -> ", pRootNode->data);
    PreOrderBinTreeNode(pRootNode->pLeftChild);
    PreOrderBinTreeNode(pRootNode->pRightChild);
  }
}

void InOrderBinTree(BinTree *pBinTree)
{
  if (pBinTree != NULL)
  {
    InOrderBinTreeNode(pBinTree->pRootNode);
  }
}
void InOrderBinTreeNode(BinTreeNode* pRootNode)
{
  if (pRootNode == NULL)
    return ;
  InOrderBinTreeNode(pRootNode->pLeftChild);
  pRootNode->visited = TRUE;
  printf("%c -> ", pRootNode->data);
  InOrderBinTreeNode(pRootNode->pRightChild);
}

void PostOrderBinTree(BinTree *pBinTree)
{
  if (pBinTree != NULL)
    PostOrderBinTreeNode(pBinTree->pRootNode);
}

void PostOrderBinTreeNode(BinTreeNode* pRootNode)
{
  if (pRootNode == NULL)
    return ;
  PostOrderBinTreeNode(pRootNode->pLeftChild);
  PostOrderBinTreeNode(pRootNode->pRightChild);
  pRootNode->visited = TRUE;
  printf("%c -> ", pRootNode->data);
  
}

void displayVisited(BinTree *pBinTree)
{
  if (pBinTree != NULL)
    displayVisitedNode(pBinTree->pRootNode);
}

void displayVisitedNode(BinTreeNode* pRootNode)
{
  if (pRootNode != NULL) 
  {
    printf("%c Node Visited : %d\n", pRootNode->data, pRootNode->visited);
    displayVisitedNode(pRootNode->pLeftChild);
    displayVisitedNode(pRootNode->pRightChild);
  }
}

void clearVisited(BinTree *pBinTree)
{
  if (pBinTree != NULL)
    clearVisitedNode(pBinTree->pRootNode);
}

void clearVisitedNode(BinTreeNode* pRootNode)
{
  if (pRootNode != NULL) 
  {
    pRootNode->visited = FALSE;
    clearVisitedNode(pRootNode->pLeftChild);
    clearVisitedNode(pRootNode->pRightChild);
  }
}
