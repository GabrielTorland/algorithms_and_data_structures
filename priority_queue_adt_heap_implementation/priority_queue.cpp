//
// Created by MSI Gaming PC on 10/27/2021.
//

#include "priority_queue.h"

bool isFull(Queue queue){
    return queue->size == queue->capacity;
}

bool isEmpty(Queue queue){
    return queue->size == 0;
}

Queue CreateQueue(int size){
    auto priorityQueue = (Queue)malloc(sizeof(struct HeapStruct));
    priorityQueue->size = 0;
    priorityQueue->capacity = size;
    priorityQueue->elements = (int *)malloc((size+1)*sizeof(int));
    return priorityQueue;
}

void insert(Queue queue, int element){
    int i;
    if (isFull(queue)){
        printf("Priority queue is full!");
        return;
    }
    for (i = ++queue->size; queue->elements[(int)floor((double )i/2)]>element; (int)floor(i/=2)){
        queue->elements[i] = queue->elements[(int)floor((double )i/2)];
    }
    queue->elements[i] = element;
}

int deleteMin(Queue queue){
    if (isEmpty(queue)){
        printf("Priority queue is empty!");
        return queue->elements[0];
    }
    int min_element = queue->elements[1];
    int child;
    for (int i = 1; i < queue->size; i = child){
        if (2*i <= queue->size && 2*i+1 <= queue->size){
            if (queue->elements[2*i] > queue->elements[2*i+1])
                child = 2*i+1;
            else
                child = 2*i;
        }
        else{
            // Only need to check for one left because it's a complete binary tree(heap).
            if (2*i <= queue->size)
                child = 2*i;
            else
                break;
        }
        queue->elements[i] = queue->elements[child];

    }
    queue->size--;
    return min_element;
}

// Min heap.
void heapify(int *arr, int n, int i){
    int smallest = i;
    int l = 2*i;
    int r = 2*i+1;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i){
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(int *arr, int n){
    int startIdx = (n/2)-1;

    for (int i = startIdx; i >= 0; --i){
        heapify(arr, n, i);
    }
}

void changeElement(Queue heap, int element, int newValue, int current){
    // Found the given element.
    if (element == heap->elements[current]){
        // Changing the given element to newVal.
        heap->elements[current] = newValue;
        // Heapify the heap.
        heapify(heap->elements, heap->size+1, current);
    }
    /* Visiting all the nodes recursively: */
    // Left child.
    if (2*current <= heap->size && element >= heap->elements[current]){ changeElement(heap, element, newValue, current*2); }
    // Right child.
    if (2*current+1 <= heap->size && element >= heap->elements[current]){ changeElement(heap, element, newValue, current*2+1); }

}

void FirstKElements(int *arr, int size, int k){
    int root = 1;
    for (int i = k; i < size; ++i){
        if (arr[i] > arr[root])
            continue;
        else{
            arr[root] = arr[i];
        }
    }
    printf("The %d smallest elements: \n", k);
    for (int i = 1; i <= k; ++i){
        if (i == k)
            printf("%d.",arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("\n");
}