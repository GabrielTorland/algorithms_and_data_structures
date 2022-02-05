#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include <ctype.h>

#define MinStackSize 50
#define MaxStackSize 500000

int isFull(Stack_strings *stack)
{
    return stack->topOfStack == stack->capacity - 1;
}

int isEmpty(Stack_strings *stack)
{
    return stack->topOfStack == -1;
}

int isEmpty_int(Stack *stack)
{
    return stack->topOfStack == -1;
}

int isFull_int(Stack *stack)
{
    return stack->topOfStack == stack->capacity - 1;
}

void push(Stack_strings *stack, char element){
    if (isFull(stack))
        printf("Stack Overflow condition!\n");
    else{
        int index = stack->topOfStack;
        stack->array[index+1] = element;
        stack->topOfStack = index+1;
    }
}

void push_int(Stack *stack, int element){
    if (isFull_int(stack))
        printf("Stack Overflow condition!\n");
    else{
        int index = stack->topOfStack;
        stack->array[index+1] = element;
        stack->topOfStack = index+1;
    }
}


char peek(Stack_strings *stack)
{
    if (isEmpty(stack))
        return '0';
    return stack->array[stack->topOfStack];
}

int peek_int(Stack_strings *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->topOfStack];
}

char pop(Stack_strings *stack, int index){
    if (isEmpty(stack)){
        return '0';
    }
    else if (index > stack->capacity-1){
        printf("Bad indexing, out of range!\n");
        return '0';
    }
    char temp_element = stack->array[index];
    if (index < stack->topOfStack){
        for (int i = index;i < (stack->topOfStack); i++){
            stack->array[i] = stack->array[i+1];
            if (i == (stack->topOfStack-1))
                stack->topOfStack = i;
        }
    }
    else{
        stack->topOfStack = index-1;
    }

    return temp_element;
}
int pop_int(Stack *stack, int index){
    if (isEmpty_int(stack)){
        return INT_MIN;
    }
    else if (index > stack->capacity-1){
        printf("Bad indexing, out of range!\n");
        return INT_MIN;
    }
    int temp_element = stack->array[index];
    if (index < stack->topOfStack){
        for (int i = index;i < (stack->topOfStack); i++){
            stack->array[i] = stack->array[i+1];
            if (i == (stack->topOfStack-1))
                stack->topOfStack = i;
        }
    }
    else{
        stack->topOfStack = index-1;
    }

    return temp_element;
}

int inspect_top_of_stack(Stack_strings *stack){
    if (isEmpty(stack))
        return INT_MIN;
    else
        return stack->topOfStack;
}

int inspect_top_of_stack_int(Stack *stack){
    if (isEmpty_int(stack))
        return INT_MIN;
    else
        return stack->topOfStack;
}

int stack_size(Stack_strings *stack){
    return stack->capacity;
}

int stack_size_int(Stack *stack){
    return stack->capacity;
}

void empty_stack(Stack_strings *stack){
    stack->topOfStack = -1;
}

void empty_stack_int(Stack *stack){
    stack->topOfStack = -1;
}

Stack_strings *create_stack_char(int stack_size){
    Stack_strings *stack = (Stack_strings *)malloc(sizeof (Stack_strings));
    stack->capacity = stack_size;
    stack->array = (char *)malloc(stack_size*sizeof(char));
    stack->topOfStack = -1;
    return stack;
}

Stack *create_stack_int(int stack_size){
    Stack *stack = (Stack *)malloc(sizeof (Stack));
    stack->capacity = stack_size;
    stack->array = (int *)malloc(stack_size*sizeof(int));
    stack->topOfStack = -1;
    return stack;
}

void task_3(Stack_strings *stack){
    int i = 0;
    int last_added;
    while (1){
        if (i != (stack->capacity-1)){
            printf("Type word\n");
            char temp_char;
            scanf("%c", &temp_char);
            getc(stdin);

            if (temp_char == ')'){
                if (stack->topOfStack == -1){
                    printf("Error!\n");
                }
            }
            else if (temp_char == '('){
                push(stack, temp_char);
                last_added= i;
                i++;
            }
            else if (temp_char == ' '){
                if (stack->topOfStack != -1)
                    printf("Index error, index=%i!\n", stack->topOfStack);
                break;
            }
            else{
                printf("%c\n", pop(stack, stack->topOfStack));
                if (last_added-1 == stack->topOfStack){
                    printf("Error!\n");
                }
            }
        }
        else
            break;
    }
}

int PSN_calculator(Stack *stack){
    printf("Casio calculator(RPN):\n");
    while (!isFull_int(stack)){
        char value;
        scanf("%c", &value);
        getc(stdin);
        if (isdigit(value))
            push_int(stack, atoi(&value));
        else{
            int x = pop_int(stack, stack->topOfStack);
            int y = pop_int(stack, stack->topOfStack);
            if (value == '+')
                push_int(stack, x+y);
            else if (value == '-')
                push_int(stack, y-x);
            else if (value == '*')
                push_int(stack, x*y);
            else if (value == '/'){
                if (x != 0)
                    push_int(stack, y/x);
                else{
                    printf("Error, not possible to divide by zero!\n");
                    return 1;
                }
            }
            else if (value == 'C')
                return 1;
            else if (value == 'O')
                return 0;
            else{
                printf("Syntax error!\n");
                return 1;
            }
        }
        for (int i = 0; i<=stack->topOfStack; i++){
            printf("%i", stack->array[i]);
        }
        printf("\n");
    }
}
int main() {
    srand(time(0));
    //Stack_strings *stack = create_stack_char((rand() % (MaxStackSize - MinStackSize + 1)) + MinStackSize);
    //task_3(stack);
    Stack *stack = create_stack_int(10);
    int state = 1;
    while (state){
        state = PSN_calculator(stack);
    }
    /*push(stack, 1);
    push(stack, 69);
    push(stack, 420);
    push(stack, 2442);
    printf("Original last index %i.\n", inspect_top_of_stack(stack));
    printf("Removed element: %i. Index: %i.\n", pop(stack, 2), 2);
    printf("Last index: %i.\n", inspect_top_of_stack(stack));
    printf("Last value %i.\n", peek(stack));
    printf("Stack size: %i.\n", stack_size(stack));*/

    return 0;
}
