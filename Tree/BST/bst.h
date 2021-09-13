#ifndef _BST_
#define _BST_

#include <stdlib.h>
#include <stdio.h>


typedef struct BinSearchTreeNodeType
{
	int key; //중복이 안된다.
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode *pRootNode;
} BinSearchTree;

BinSearchTree* createBinSearchTree();
BinSearchTreeNode *createBinSearchNode(int key, char value);

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode *element);
int deleteElementBST(BinSearchTree* pBinSearchTree, int key);

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key);

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key);

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

void InOrderBinTree(BinSearchTree *pBinSearchTree);
void InOrderBinTreeNode(BinSearchTreeNode *element);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
