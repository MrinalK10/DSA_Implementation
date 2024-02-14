
// Single array to implement two stack.
// They start from opposite end of array and grow towards each other


#include <stdio.h>
#define MAXSIZE 10

typedef struct stack{
    int top1;
    int top2;
    int arr[MAXSIZE];
}STACK;

int isFull(STACK* st1,STACK* st2){
    return st1->top1+1==st2->top2;
}

int isEmpty1(STACK* st){
    return st->top1==-1;
}

int isEmpty2(STACK* st){
    return st->top2==MAXSIZE;
}

void push1(STACK* st1,STACK* st2,int data){
    if(isFull(st1,st2)){
        printf("Stack is Full\n");
        return;
    }
    
    st1->arr[++st1->top1]=data;

}

void push2(STACK* st1,STACK* st2,int data){
    if(isFull(st1,st2)){
        printf("Stack is Full\n");
        return;
    }
    
    st2->arr[--st2->top2]=data;

}

int pop1(STACK* st){
    if(isEmpty1(st)){
        printf("Stack is Empty\n");
        return -1;
    }

    return st->arr[st->top1--];
}

int pop2(STACK* st){
    if(isEmpty2(st)){
        printf("Stack is Empty\n");
        return -1;
    }

    return st->arr[st->top2++];
}

int peek1(STACK* st){
    if(isEmpty1(st)){
        printf("Stack is Empty\n");
        return -1;
    }

    return st->arr[st->top1];
}

int peek2(STACK* st){
    if(isEmpty2(st)){
        printf("Stack is Empty\n");
        return -1;
    }

    return st->arr[st->top2];
}

void display1(STACK* st){
    if(isEmpty1(st)){
        printf("Stack is Empty\n");
        return ;
    }

    printf("Stack1:");

    for(int i=st->top1;i>=0;i--){
        printf("%d|",st->arr[i]);
    }
    
    printf("\n");



}

void display2(STACK* st){
    if(isEmpty2(st)){
        printf("Stack is Empty\n");
        return ;
    }

    printf("Stack2:");

    for(int i=st->top2;i<MAXSIZE;i++){
        printf("%d|",st->arr[i]);
    }

    


}

// Main function for verification 



int main(){

    STACK st1;
    STACK st2;



    st1.top1=-1;
    st2.top2=MAXSIZE;

    push1(&st1,&st2,15);
    push1(&st1,&st2,25);
    push1(&st1,&st2,35);
    push2(&st1,&st2,55);
    push2(&st1,&st2,65);
    push2(&st1,&st2,75);
    pop1(&st1);
    pop2(&st2);


    display1(&st1);
    display2(&st2);








    return 0;
}








