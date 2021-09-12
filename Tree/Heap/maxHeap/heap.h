#ifndef _HEAP_H_
# define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 16

typedef struct heapNode
{
  int data;
} element;

typedef struct heap
{
    element array[MAX_LIST_SIZE];
    int size;
} heapList;

void createHeap(heapList *L, int data);
void deleteHeap(heapList *L);
void insertElement(heapList *L, int data);
int removeElement(heapList *L);
void swap(int *A, int *B);
void display(heapList *L);

#endif
