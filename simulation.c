#include "simulation.h"
#include "PQueueADT.h"

FILE *openFile(char *filename)
{
   FILE *tempFile;

   tempFile = fopen(filename, "r");

   if (tempFile == NULL)
   {
      while (tempFile == NULL)
      {
         printf("File can't be open. Please try again!");
         exit(0);
      }
   }
   return tempFile;
}

void parsingLine(char line[], clientData *loadData)
{
   char *token;
   int length = 0;

   token = strtok(line, " ");
   length = strlen(token);
   strncpy(loadData->clientID, token, length);
   token = strtok(NULL, " ");
   loadData->priority1 = atoi(token);
   loadData->priority2 = atoi(token);
   token = strtok(NULL, " ");
   strncpy(loadData->code, token, 2);
}

FILE *writeToFile(clientData *toWrite, int num, int sum)
{
   FILE *tempFile = NULL;
   int i = 0;

   tempFile = fopen("report.txt", "w");
   for (i = 0; i < num; i++)
   {
      fprintf(tempFile, "%d. Client ID: %s\nInitial priority: %d, Final priority: %d\nSymptom Code: %s\nArrival Time: %d\nTime Per Client: %d\n\n", i+1, toWrite[i].clientID, toWrite[i].priority1, toWrite[i].priority2, toWrite[i].code, toWrite[i].arrivalTime, toWrite[i].leavingTime);
   }

   fprintf(tempFile, "Total time spend: %d", sum);

   return tempFile;

}
