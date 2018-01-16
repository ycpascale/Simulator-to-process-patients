#ifndef _FUNC_
#define _FUNC_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "PQueueADT.h"

/**Function to open the file and read it
*@return a file pointer if the file to be read is present
*@param filename pointer to the name of the file to be opened and read
**/
FILE *openFile(char *filename);

/**Function to pase through each line read
*@param line which contains the data
*@param loadData pointer to a struct in which the data is loaded.
**/
void parsingLine(char line[], clientData *loadData);

/**Function to create a file and write data in the file
*@param toWrite pointer to the struct that contains the data that has to been written in the file
*@param sum indicates the amount of time spent for the simulation
**/
FILE *writeToFile(clientData *toWrite, int num, int sum);

#endif
