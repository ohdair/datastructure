#include "BinTree_AL.h"

int main(){
  TreeAL *L = (TreeAL*)malloc(sizeof(TreeAL));

  makeRoot(L, 'A');
  InsertLeftChildAL(L, 1, 'B');
  InsertRightChildAL(L, 1, 'C');
  display(L);
}
