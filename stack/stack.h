//
// Created by gabri on 06.09.2021.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef struct
{
    int capacity;
    int topOfStack;
    int* array;
} Stack;

typedef struct
{
    int capacity;
    int topOfStack;
    char *array;
} Stack_strings;

#endif //STACK_STACK_H
