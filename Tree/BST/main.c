#include "bst.h"
#include <unistd.h>
#include <time.h>

int main(){
  BinSearchTree *bst_tree;
  BinSearchTreeNode *node;

  bst_tree = createBinSearchTree();
  srand(time(NULL));

  for (int i = 0; i < 16; i++) {
    node = createBinSearchNode(rand() % 16 + 1, 'a' + i);
    insertElementBST(bst_tree, node);
  }
  InOrderBinTree(bst_tree);
  printf("\n");
  deleteElementBST(bst_tree, 3);
  InOrderBinTree(bst_tree);

}
