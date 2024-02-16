#include<stdio.h>
#define MAXSIZE 100

typedef struct queue{
    int arr[MAXSIZE];
    int front,rear;
}QUEUE;

int isEmpty(QUEUE* q){
    return q->rear<q->front;
}

int isFull(QUEUE* q){
    return q->rear==MAXSIZE-1;
}

void enqueue(QUEUE* q,int data){
    if(isFull(q)){
        printf("The Queue is Full\n");
        return;
    }

    q->arr[++q->rear]=data;


}

int dequeue(QUEUE* q){
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
        return -1;
    }

    int item = q->arr[q->front];
    
    if(q->front==q->rear){
        q->front=0;
        q->rear=-1;
    }

    else{
        q->front++;
    }

    return item;

}

void display(QUEUE* q){
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
        return;
    }

    for(int i=q->front;i<=q->rear;i++){
        printf("%d <- ",q->arr[i]);
    }
}

int main(){

    QUEUE q;
    q.rear=-1;
    q.front=0;

    enqueue(&q,15);
    enqueue(&q,20);
    enqueue(&q,25);
    printf("Item Deleted:%d\n",dequeue(&q));
    // printf("%d\n",dequeue(&q));
    // printf("%d\n",dequeue(&q));
    


    display(&q);

    return 0;
}