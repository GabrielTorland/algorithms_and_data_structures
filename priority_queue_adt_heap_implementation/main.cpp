#include <iostream>
#include "priority_queue.h"

#define SIZE 51 // Size is in reality 50, but im using a dummy node.
#define STARTING_INDEX 1
#define LEFT_CHILD 2*i
#define RIGHT_CHILD 2*i+1

int main() {
    Queue priorityQueue = CreateQueue(SIZE-1);
    int temp[] = {INT_MIN, 1, 49, 48, 47, 46};
    for (int i = SIZE-1; i > 0; --i){
        insert(priorityQueue, i);
    }
    //printf("Deleted: %d\n", deleteMin(priorityQueue));
    //changeElement(priorityQueue, 1, 100, 1);
    buildHeap(temp, 5+1);

    /* k is the number of elements you want to find. */
    int k = 3;
    FirstKElements(temp, sizeof(temp)/sizeof(int), k);

    for (int i = STARTING_INDEX; i <= priorityQueue->size; ++i){
        if (LEFT_CHILD <= priorityQueue->size){
            printf("%d(%d)  ->  ", priorityQueue->elements[i], i);
            printf("Child left: %d, ", priorityQueue->elements[2*i]);
        }
        if (RIGHT_CHILD <= priorityQueue->size)
            printf("child right: %d\n", priorityQueue->elements[2*i+1]);
    }
    /*
    printf("\n");
    for (int i = STARTING_INDEX; i < SIZE; ++i){
        if (LEFT_CHILD < SIZE){
            printf("%d(%d)  ->  ", temp[i], i);
            printf("Child left: %d, ", temp[2*i]);
        }
        if (RIGHT_CHILD <= SIZE)
            printf("child right: %d\n", temp[2*i+1]);
    }
     */

    return 0;
}
