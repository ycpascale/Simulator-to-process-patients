#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
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
   int count = 0;
   int nItemRemoved = 0;
   int takeClient = 0;
   int num = 0;

   infile = openFile(argv[1]);

   client = malloc(sizeof(clientData));

   while(fgets(tempArr, LEN, infile))
   {
      parsingLine(tempArr, &client[index]);
      index++;
      client = realloc(client, sizeof(clientData) * (index+1));
   }

   fclose(infile);


   //Assigning the random arrival time to each client
   srand(time(NULL));
   for (i = 0; i < index; i++)
   {
      num = rand() % index +1;
      client[i].arrivalTime = num;
      client[i].leavingTime = 0;
   }

    //Creating the priority queue
    pqueue = create();;

    count = 1;
    takeClient = 3;
    sortedData = malloc(sizeof(clientData) * index);

    while (nItemRemoved != (index))
    {
       for (i = 0; i < index; i++)
       {
          if (client[i].arrivalTime == count)
          {
            insert(pqueue, (void*)&client[i]);
          }
       }

       if (count == takeClient)
       {
         toGet = (clientData*)getMinOrMax(pqueue->heap);

         strcpy(sortedData[nItemRemoved].clientID, toGet->clientID);
         sortedData[nItemRemoved].priority1 = toGet->priority1;
         sortedData[nItemRemoved].priority2 = toGet->priority2;
         strcpy(sortedData[nItemRemoved].code, toGet->code);
         sortedData[nItemRemoved].arrivalTime = toGet->arrivalTime;
         sortedData[nItemRemoved].leavingTime = sortedData[nItemRemoved].arrivalTime + count;

         removeMin(pqueue);
         nItemRemoved++;
         takeClient = takeClient + 3;
       }

       count = count + 1;
    }

    infile = writeToFile(sortedData, index, count);
    free(client);
    

   return 0;
}
