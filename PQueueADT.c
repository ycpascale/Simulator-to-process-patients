#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "PQueueADT.h"


PQueue *create()
{
   PQueue *pqueue;

   HEAP_TYPE w = MIN_HEAP;

   pqueue = malloc(sizeof(pqueue));
   pqueue->heap = createHeap(100, w, &destroyDataFP, &printNodeFP, &compareFP);
   pqueue->counter = 0;
   pqueue->nClients = 0;
   pqueue->lastPosn = 0;

   return pqueue;

}

void insert(PQueue *pq, void *element)
{
   insertHeapNode(pq->heap, element);
   pq->nClients++;
}



void removeMin(PQueue *pq)
{

/*  int i = 0;
  clientData *info;

   pq->counter++;
   if (pq->counter == 2)
   {
      for (i = pq->lastPosn+1; i < pq->nClients; i++)
      {
         info = (clientData*)pq->heap->heapNode[i].data;
         if (info->priority2 > 1)
         {
            info->priority2 = info->priority2 - 1;
         }
      }
      pq->counter = 0;
   }*/

   deleteMinOrMax(pq->heap);
   pq->nClients--;
   pq->lastPosn++;
}

bool isEmpty(PQueue *pq)
{
  if (pq->heap->count== 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void destroy(PQueue *pq)
{
   deleteHeap(pq->heap);
   free(pq);
}
