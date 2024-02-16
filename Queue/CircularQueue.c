#include <stdio.h>
#define MAXSIZE 5

typedef struct {
    int arr[MAXSIZE];
    int rear,front,count;
    
}CQUEUE;

void createQueue(CQUEUE* q){
    q->rear=MAXSIZE-1;
    q->front=MAXSIZE-1;
    q->count=0;
}

int isEmpty(CQUEUE* q){
    return q->count==0;
}

int isFull(CQUEUE* q){
    return q->count==MAXSIZE;
}

void enqueue(CQUEUE* q , int data){
    if(isFull(q)){
        printf("Queue is Full\n");
        return;
    }

    
    q->rear=(q->rear+1)%MAXSIZE;

    q->arr[q->rear]=data;

    q->count++;

    
}

int dequeue(CQUEUE* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }

    q->front=(q->front+1)%MAXSIZE;

    q->count--;

    return q->arr[q->front];
}

void display(CQUEUE* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    int i = (q->front + 1) % MAXSIZE;
    printf("Queue elements: ");
    for (int j = 0; j < q->count; j++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main(){

    CQUEUE cq;
    createQueue(&cq);

    enqueue(&cq,15);
    enqueue(&cq,25);
    enqueue(&cq,35);
    enqueue(&cq,45);
    enqueue(&cq,55);

    dequeue(&cq);
    dequeue(&cq);
    enqueue(&cq,65);
    enqueue(&cq,75);

    display(&cq);




    return 0;
}
