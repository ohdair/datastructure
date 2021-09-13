#include "bst.h"
#include <unistd.h>
#include <time.h>

int main(){
  BinSearchTree *bst_tree;
  BinSearchTreeNode *node;

  bst_tree = createBinSearchTree();
//   write(1, "10", 2);
  srand(time(NULL));

  for (int i = 0; i < 16; i++) {
	// write(1, "14", 2);
    node = createBinSearchNode(rand() % 16 + 1, 'a' + i);
	// write(1, "16", 2);
    insertElementBST(bst_tree, node);
	// write(1, "18", 2);
  }
  deleteElementBST(bst_tree, 15);
  InOrderBinTree(bst_tree);

}
