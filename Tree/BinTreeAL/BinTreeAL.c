#include "BinTree_AL.h"

// Start
void makeRoot(TreeAL *Lptr, char data){
  Lptr->TreeArray[1].data = data;
  Lptr->count++;
}

void InsertLeftChildAL(TreeAL *Lptr, int position, char data){
  if (position < 1 || position * 2 >= MAXSIZE)
  {
    printf("Error : Out of the range");
    return ;
  }
  else if (Lptr->TreeArray[position * 2].data != 0)
  {
    printf("Error : LeftChild is FULL");
    return ;
  }
  Lptr->TreeArray[position * 2].data = data;
  Lptr->count++;
}

void InsertRightChildAL(TreeAL *Lptr, int position, char data){
  if (position < 1 || (position * 2) + 1 >= MAXSIZE)
  {
    printf("Error : Out of the range");
    return ;
  }
  else if (Lptr->TreeArray[(position * 2) + 1].data != 0)
  {
    printf("Error : RightChild is FULL");
    return ;
  }
  Lptr->TreeArray[(position * 2) + 1].data = data;
  Lptr->count++;
}

char getLeftChildAL(TreeAL *Lptr, int position)
{
  char ret = Lptr->TreeArray[position * 2].data;
  if (ret == 0)
  {
    printf("Error : LeftChild is Empty");
    return 0;
  }
  return ret;
}

char getRightChildAL(TreeAL *Lptr, int position)
{
  char ret = Lptr->TreeArray[(position * 2) + 1].data;
  if (ret == 0)
  {
    printf("Error : RightChild is Empty");
    return 0;
  }
  return ret;
}
void display(TreeAL *Tree) {
  for (int i = 1; i <= Tree->count; i++)
    printf("%c ", Tree->TreeArray[i].data);
  printf("\n");
}

void deleteTreeAL(TreeAL *Tree){
  for (int i = Tree->count; i > 0; i--)
    Tree->TreeArray[i].data = 0;
}

