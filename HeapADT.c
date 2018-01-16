#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "other.h"


Heap *createHeap(size_t initialSize, HEAP_TYPE htype, void (*destroyDataFP)(void *data),void (*printNodeFP)(void *toBePrinted),int (*compareFP)(const void *first, const void *second))
{
   Heap *newHeap;

   newHeap = malloc(sizeof(Heap));
   newHeap->heapNode = malloc(sizeof(Node) *initialSize);
   newHeap->type = htype;
   newHeap->count = 1;
   newHeap->destroyData = destroyDataFP;
   newHeap->printNode = printNodeFP;
   newHeap->compare = compareFP;

   return newHeap;
}

Node *createHeapNode(void *data)
{
   Node *newNode;

   newNode = malloc(sizeof(Node));
   newNode->parent = NULL;
   newNode->data = data;

   return newNode;
}

void insertHeapNode(Heap *heap, void *data)
{
   Node *toBeAdded;
   double i = 0;
   int index = 0;
   double j = 0;
   int a = 0;

   toBeAdded = createHeapNode(data);

   index = heap->count;

   if (index == 1)
   {
      heap->heapNode[index].data = toBeAdded->data;
      heap->heapNode[index].parent = toBeAdded;
      index = index  + 1;
   }
   else
   {
       heap->heapNode[index].data = toBeAdded->data;
       i = index / 2;
       j = floor(i);
       a = (int)j;
       heap->heapNode[index].parent = heap->heapNode[a].parent;
       heapifyUp(heap, index);
       index = index + 1;
   }

   heap->count = index;
}



void heapifyUp(Heap *heap, int index)
{
   int pIndex = 0;
   double i = 0;
   Node *tempNode;

   tempNode = malloc(sizeof(Node));

   i = index / 2;
   i = floor(i);
   pIndex = (int)i;

    while (pIndex != 0)
   {
     if (heap->compare(heap->heapNode[index].data, heap->heapNode[pIndex].data) < 0)
     {
      tempNode->data = heap->heapNode[pIndex].data;
      tempNode->parent = heap->heapNode[pIndex].parent;
      heap->heapNode[pIndex].data = heap->heapNode[index].data;
      heap->heapNode[pIndex].parent = heap->heapNode[index].parent;
      heap->heapNode[index].data = tempNode->data;
      heap->heapNode[index].parent = tempNode->parent;

      index = pIndex;
      i = index / 2;
      i = floor(i);
      pIndex = (int)i;

     }
     else
     {
        pIndex = 0;
     }
   }
   free(tempNode);
}

void deleteMinOrMax(Heap *heap)
{
   Node *tempNode;
   int index = 0;

   tempNode = malloc(sizeof(Node));
   index = heap->count;
   index = index - 1;

   tempNode->data = heap->heapNode[1].data;
   heap->heapNode[1].data = heap->heapNode[index].data;
   heap->heapNode[index].data = NULL;
   minHeapify(heap, 1, index);
   heap->count = index;
   free(tempNode);

}

void destroyDataFP(void *data)
{
   free((Node*)data);
}

void minHeapify(Heap *heap, int root, int max)
{
   int left = 0;
   int right = 0;
   Node *tempNode;

   tempNode = malloc(sizeof(Node));
   left = 2 * root;
   right = (2 * root) + 1;

   if (left < max)
   {
      //check if right ena zafr
      if (heap->heapNode[right].data != NULL)
      {
        // check if lc < p
        if (heap->compare(heap->heapNode[left].data, heap->heapNode[root].data) < 0)
        {
           // is rc > p too?
           if (heap->compare(heap->heapNode[right].data, heap->heapNode[root].data) < 0)
           {
              //checking if lc > rc
              if (heap->compare(heap->heapNode[left].data, heap->heapNode[right].data) < 0)
              {
                   //lc > p
                   tempNode->data = heap->heapNode[root].data;
                   heap->heapNode[root].data = heap->heapNode[left].data;
                   heap->heapNode[left].data = tempNode->data;
                   minHeapify(heap, left, max);
              }
              else if (heap->compare(heap->heapNode[right].data, heap->heapNode[left].data) < 0)
              {

                  //swaping between rc and p as rc > p
                  tempNode->data = heap->heapNode[root].data;
                  heap->heapNode[root].data = heap->heapNode[right].data;
                  heap->heapNode[right].data = tempNode->data;
                  minHeapify(heap, right, max);
              }
           }
           else //only lc > p
           {

              tempNode->data = heap->heapNode[root].data;
              heap->heapNode[root].data = heap->heapNode[left].data;
              heap->heapNode[left].data = tempNode->data;
              minHeapify(heap, left, max);
           }
        }
        // lerla fini kner kpv rc < p
        else if (heap->compare(heap->heapNode[right].data, heap->heapNode[root].data) < 0)
        {
           tempNode->data = heap->heapNode[root].data;
           heap->heapNode[root].data = heap->heapNode[right].data;
           heap->heapNode[right].data = tempNode->data;
           minHeapify(heap, right, max);
        }
        else
        {

           return;
        }
      }
      // if there is nothing on the right we check for left.. and this usually happens at the last line
      else if (heap->heapNode[right].data == NULL)
      {
          //check if lc < p
          if (heap->compare(heap->heapNode[left].data, heap->heapNode[root].data) < 0)
          {
             tempNode->data = heap->heapNode[root].data;
             heap->heapNode[root].data = heap->heapNode[left].data;
             heap->heapNode[left].data = tempNode->data;
          }
          else
          {

             return;
          }
      }
   }
   free(tempNode);
}


void *getMinOrMax(Heap *heap)
{
   Node *tempNode;

   tempNode = heap->heapNode[1].data;

   return tempNode;
}

void changeHeapType(Heap *heap)
{
   return;
}

void deleteHeap(Heap *heap)
{
   free(heap->heapNode);
   free(heap);
}

int compareFP(const void *first, const void *second)
{
   struct info *ia = (struct info*)first;
   struct info *ib = (struct info*)second;

   if ((ia->priority2) > (ib->priority2))
   {
      return (1);
   }
   else
   {
      return (-1);
   }
}

void printNodeFP(void *data)
{
   info *toPrint;

   toPrint = (info*)data;
   printf("The patient with priority is %d clientID: %s code: %s\n\n", toPrint->priority1, toPrint->clientID, toPrint->code);

}
