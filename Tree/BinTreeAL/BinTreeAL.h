#ifndef _BIN_TREE_AL_
#define _BIN_TREE_AL_

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 16


typedef struct TreeNodeAL
{
  char data;
} TreeNodeAL;

typedef struct TreeAL
{
  int count;
  TreeNodeAL TreeArray[MAXSIZE];
} TreeAL;

void makeRoot(TreeAL *Lptr, char data);
void InsertLeftChildAL(TreeAL *Lptr, int position, char data);
void InsertRightChildAL(TreeAL *Lptr, int position, char data);
char getLeftChildAL(TreeAL *Lptr, int position);
char getRightChildAL(TreeAL *Lptr, int position);
void display(TreeAL *Tree);
void deleteTreeAL(TreeAL *Tree);


#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 	1
#define FALSE	0

#endif
