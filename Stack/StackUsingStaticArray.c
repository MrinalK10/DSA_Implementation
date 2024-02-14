#include <stdio.h>
#define MAXSIZE 10

typedef struct stack{
    int arr[MAXSIZE];
    int top;

}STACK;

int isEmpty(STACK* st){
    return st->top==-1;
}

int isFull(STACK* st){
    return st->top==MAXSIZE-1;
}

void push(STACK* st,int data){
    if(isFull(st)){
        printf("Stack Overflow\n");
        return;
        }

    st->arr[++st->top]=data;
}

int pop(STACK* st){
    if(isEmpty(st)){
        printf("Stack Underflow\n");
        return -1;
    }

    return st->arr[st->top--];
}

int peek(STACK* st){
    if(isEmpty(st)){
        printf("Stack Underflow\n");
        return -1;
    }

    return st->arr[st->top];
}

void display(STACK* st){
    if(isEmpty(st)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack:");
    for(int i=st->top;i>=0;i--){
        printf("%d|",st->arr[i]);
    }
}

// Main function for verification 
// For Menu Driven look up to SinglyLinkedList

int main(){

    STACK st;
    st.top=-1;

    push(&st,5);
    push(&st,15);
    push(&st,25);

    

    printf("Item Deleted:%d\n",pop(&st));

    printf("Top of the stack:%d\n",peek(&st));
    
    display(&st);

    





    return 0;
}