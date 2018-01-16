/**
 * @file PQueueADT.h
 * @author Pascale Young Choang
 * @date July 2017
 * @brief File containing the function definitions of a priority queue
 */

#ifndef _PQ_API_
#define _PQ_API_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "other.h"

typedef struct clientData
{
   char clientID[50];
   int priority1;
   int priority2;
   char code[2];
   int arrivalTime;
   int leavingTime;

}clientData;

typedef struct PQueue
{
   Heap *heap;
   int counter;  //this is for the time interval
   int nClients; //this is number of clients in the queue
   int lastPosn;

}PQueue;

/**Function to create a priority queue which encapsulate a heap
*@return pointer to a priority queue
**/
PQueue *create();

/**Function to insert a data in the priority queue
*@pre 'pq' type must already exist
*@param pq pointer to a priority queue
*@param element a pointed that contains the struct that is to be added into the pq
**/
void insert(PQueue *pq, void *element);

/**Function to remove the root of the queue
*@param pq pointer to a priority queue
**/
void removeMin(PQueue *pq);

/** Function to verify if the queue is empty or not
*@pre pq might already exist or might not
*@pq pq pointer to a prioriy queue which has already been iniatlised
**/
bool isEmpty(PQueue *pq);

/**Function to destroy the queue completely
*@param pq pointer to a priority queue so as to be able to point to the heap and free the data inside
**/
void destroy(PQueue *pq);

#endif
