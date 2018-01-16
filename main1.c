#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "simulation.h"
#include "PQueueADT.h"

#define SIZE 25
#define LEN 200

int main(int argc, char* argv[])
{
   FILE* infile = NULL;
   PQueue *pqueue;
   clientData *client;
   clientData *toGet;
   clientData *sortedData;
   char tempArr[LEN];
   int index = 0;
   int i = 0;

   infile = openFile(argv[1]);

   client = malloc(sizeof(clientData));

   while(fgets(tempArr, LEN, infile))
   {
      parsingLine(tempArr, &client[index]);
      index++;
      client = realloc(client, sizeof(clientData) * (index+1));
   }

   fclose(infile);

   for (i = 0; i < index; i++)
   {
      client[i].arrivalTime = 0;
      client[i].leavingTime = 0;
   }

    //Creating the priority queue
    pqueue = create();

    //loading the structs into the priority queue
    for (i = 0; i < index; i++)
    {
       insert(pqueue, (void*)&client[i]);
    }

    sortedData = malloc(sizeof(clientData) * index);
    for (i = 0; i < index; i++)
    {

      toGet = (clientData*)getMinOrMax(pqueue->heap);
      strcpy(sortedData[i].clientID, toGet->clientID);
      sortedData[i].priority1 = toGet->priority1;
      sortedData[i].priority2 = toGet->priority2;
      strcpy(sortedData[i].code, toGet->code);
      sortedData[i].arrivalTime = 0;
      sortedData[i].leavingTime = 0;

      removeMin(pqueue);
    }

    infile = writeToFile(sortedData, index, 0);

   return 0;
}
