#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr;
    int top;
    int initialSize;
} STACK;

STACK *createStack(int initialSize)
{

    STACK *st = (STACK *)malloc(sizeof(STACK));

    if (st == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }

    int *arr = (int *)malloc(sizeof(int) * initialSize);

    if (arr == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }

    st->arr = arr;
    st->initialSize = initialSize;
    st->top = -1;

    return st;
}

int resize(STACK *st, int incr_size)
{
    int newSize = st->initialSize + incr_size;

    int *new = (int *)realloc(st->arr, sizeof(int) * newSize);

    if (new == NULL)
    {
        printf("Memory Allocation failed\n");
        return 0;
    }

    st->arr = new;
    st->initialSize = newSize;

    return 1;
}

int isEmpty(STACK *st)
{
    return st->top == -1;
}

void push(STACK *st, int data)
{
    if (st->top == st->initialSize - 1)
    {
        // Checking memory allocation and increasing size of stack by 1
        if (!(resize(st, 1)))
        {
            printf("Stack Overflow\n");
        }
    }

    st->arr[++st->top]=data;


}

int pop(STACK* st){
    if(isEmpty(st)){
        printf("Empty Stack\n");
        return -1;
        }

    int item = st->arr[st->top--];

    // Memory can't be allocated -1 times

    if(st->top!=0){
        resize(st,-1);
    }

    return item;
}

int peek(STACK* st){
     if(isEmpty(st)){
        printf("Empty Stack\n");
        return -1;
        }

    return st->arr[st->top];
}

void display(STACK* st){
    if(isEmpty(st)){
        printf("Empty Stack\n");
        return ;
        }

        printf("Stack:");
    
    for(int i=st->top;i>=0;i--){
        printf("%d|",st->arr[i]);
    }
}

void destroyStack(STACK* st){
    free(st->arr);
    free(st);
}


// Main function for verification 
// For Menu Driven look up to SinglyLinkedList

int main(){

    STACK* st = createStack(3);

    push(st,15);
    push(st,25);
    push(st,35);

    printf("Item Deleted:%d\n",pop(st));
    printf("Item Deleted:%d\n",pop(st));
    

    printf("Top of stack:%d\n",peek(st));

    display(st);

    destroyStack(st);


    return 0;
}