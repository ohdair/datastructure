#include "heap.h"

void swap(int *A, int *B)
{
  int tmp;
  
  tmp = *A;
  *A = *B;
  *B = tmp;
}

void createHeap(heapList *L, int data)
{
  L->array[1].data = data;
  L->size = 1;
}

void deleteHeap(heapList *L)
{
  for (int i = L->size; i > 0; --i)
    L->array[i].data = 0;
  free(L);
}

void insertElement(heapList *L, int data)
{
  int position = ++L->size;

  L->array[position].data = data;
  while (position > 1)
  {
    if (L->array[position].data <= L->array[position / 2].data)
      return ;
    else
    {
      /*
      tmp = L->array[position].data;
      L->array[position].data = L->array[position / 2].data;
      L->array[position / 2].data = tmp;
      */
      swap(&L->array[position].data, &L->array[position / 2].data);
    }
    position /= 2;
  }
}

int removeElement(heapList *L)
{
  int i = 1; // 루트 노드에서 자료 이동이 멈출 때까지 배열 위치
  int position = L->size--;
  int ret = L->array[1].data;

  L->array[1].data = L->array[position].data;
  L->array[position].data = 0;
  while (i < L->size)
  {
    if (L->array[i].data > L->array[i * 2].data && L->array[i].data > L->array[(i * 2) + 1].data)
      break;
    else if (L->array[i].data < L->array[i * 2].data || L->array[i].data < L->array[(i * 2) + 1].data)
    {
      if (L->array[i * 2].data > L->array[i * 2 + 1].data)
      {
        swap(&L->array[i].data, &L->array[i * 2].data);
        i = i * 2;
      }
      else
      {
        swap(&L->array[i].data, &L->array[i * 2 + 1].data);
        i = i * 2 + 1;
      }
    }
  }
  return ret;
}

void display(heapList *L) {
  for (int i = 1; i <= L->size; i++)
    printf("%d ", L->array[i].data);
  printf("\n");
}