//
// Created by MSI Gaming PC on 10/27/2021.
//

#ifndef PRIORITY_QUEUE_ADT_HEAP_IMPLEMENTATION__PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_ADT_HEAP_IMPLEMENTATION__PRIORITY_QUEUE_H

#include <iostream>
#include <cmath>

#define CAPACITY 100

typedef struct HeapStruct *Queue;

struct HeapStruct{
    int capacity;
    int size;
    int *elements;
};

bool isFull(Queue);

bool isEmpty(Queue);

Queue CreateQueue(int);

void insert(Queue, int);

int deleteMin(Queue);

void heapify(int *, int, int);

void buildHeap(int *, int);

void changeElement(Queue , int, int, int);

void FirstKElements(int *, int, int);

#endif //PRIORITY_QUEUE_ADT_HEAP_IMPLEMENTATION__PRIORITY_QUEUE_H
