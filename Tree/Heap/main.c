#include "heap.h"

int main(void) {
  
  heapList *L = (heapList*)malloc(sizeof(heapList));
  
  createHeap(L, 37);
  insertElement(L, 84);
  insertElement(L, 100);
  insertElement(L, 10);
  insertElement(L, 200);
  insertElement(L, 17);
  insertElement(L, 84);
  insertElement(L, 10);
  display(L);
  printf("%d\n", removeElement(L));
  display(L);
  
  return 0;
}