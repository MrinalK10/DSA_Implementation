#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *arr;
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

    char *arr = (char *)malloc(sizeof(char) * initialSize);

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

    char *new = (char *)realloc(st->arr, sizeof(char) * newSize);

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

void push(STACK *st, char data)
{
    if (st->top == st->initialSize - 1)
    {
        if (!(resize(st, 1)))
        {
            printf("Stack Overflow\n");
        }
    }

    st->arr[++st->top]=data;


}

char pop(STACK* st){
    if(isEmpty(st)){
        printf("Empty Stack\n");
        return -1;
        }

    char item = st->arr[st->top--];

    if(st->top!=0){
        resize(st,-1);
    }

    return item;
}

char peek(STACK* st){
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
    
    for(int i=st->top;i>=0;i--){
        printf("%d|",st->arr[i]);
    }
}

void destroyStack(STACK* st){
    free(st->arr);
    free(st);
}


void reverseString(char letter[]){

    STACK* st = createStack(10);

    

    for(int i=0;i<strlen(letter);i++){
        push(st,letter[i]);
        }
    int i =0;
    while(!isEmpty(st)){
       letter[i]=pop(st);
       i++;
    }

    destroyStack(st);



}






int main(){

    char letter[20]="Hello World";
    reverseString(letter);
    printf("%s",letter);
    
    



    return 0;
}