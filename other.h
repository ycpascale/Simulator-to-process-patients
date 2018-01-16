#ifndef _HEAPTYPES_
#define _HEAPTYPES_
#ifndef _HEAP_API_
#define MIN_HEAP 0
#define MAX_HEAP 1
#define HEAP_TYPE unsigned char
#endif
#endif

typedef struct Node
{
   void *data;
   struct Node *parent;

}Node;

typedef struct Heap
{

    Node *heapNode;
    HEAP_TYPE type;
    Node *lastNode;
    int count;
    void (*destroyData)(void *data);
    void (*printNode)(void *toBePrinted);
    int (*compare)(const void *first, const void *last);
}Heap;

typedef struct info
{
   char clientID[50];
   int priority1;
   int priority2;
   char code[2];
   int arrivalTime;
   int leavingTime;

}info;


#include "heap.h"

/**Function that re-sort the heap from the bottom to top.
*@param heap pointer to a heap structure
*@index an integer indicating the last index at which data was added
**/
void heapifyUp(Heap *heap, int index);

/**Function  that compare 2 data in order to sort the heap
*@param first pointer to the first data
*@param second pointer to the second data
**/
int compareFP(const void *first, const void *second);

/**Function to free the data
*@param can take any type of data that need to be freed
**/
void destroyDataFP(void *data);

/*Function to min-heapify that is the smallest data is at the top.
*@heap pointer to a heap structure
*@param root pointer which points at the first index in the array used for the heap
*@max pointer to the last location where data was added on the heap
**/
void minHeapify(Heap *heap, int root, int max);

/**Function to print the data
*@param data pointer to any type of data that would be printed
**/
void printNodeFP(void *data);
