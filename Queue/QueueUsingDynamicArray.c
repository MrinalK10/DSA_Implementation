#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int* arr;
    int size,front,rear;
}QUEUE;

QUEUE* createStack(int size){
    QUEUE* myQueue = (QUEUE*)malloc(sizeof(QUEUE));

    if(myQueue==NULL){
       printf("Memory Allocation failed\n");
       exit(0);
    }

    myQueue->arr = (int*)malloc(size*sizeof(int));

    myQueue->size=size;
    myQueue->front=0;
    myQueue->rear=-1;

    return myQueue;
}

int resizeStack(QUEUE* q,int newSize){
    int capacity = q->size+newSize;
    
    int* newArr = (int*)realloc(q->arr,sizeof(int)*capacity);

    if(newArr==NULL){
       printf("Memory Allocation failed\n");
       return 0;
    }

    q->arr=newArr;
    q->size=capacity;

    return 1;

}

int isEmpty(QUEUE* q){
    return q->rear < q->front;
}

int isFull(QUEUE* q){
    return q->rear == q->size-1;
}

void enqueue(QUEUE* q,int data){
    if(isFull(q)){
        if(!resizeStack(q,1)){
            printf("Queue is Full\n");
            return;
        }

      }

    q->arr[++q->rear]=data;
}

int dequeue(QUEUE* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }

    int item = q->arr[q->front];

    if(q->rear==q->front){
        q->front=0;
        q->rear=-1;
    }
    else{
        q->front++;
        if (q->size > 5 ) {
            resizeStack(q, -1);
        }
    }

    return item;

    

}

void display(QUEUE* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return ;
    }

   for(int i=q->front;i<=q->rear;i++){
        printf("%d <- ",q->arr[i]);
    }
}

int main(){

    QUEUE* q=createStack(5);
    

    enqueue(q,15);
    enqueue(q,20);
    enqueue(q,25);
    enqueue(q,30);
    enqueue(q,35);
    enqueue(q,40);
    printf("Item Deleted:%d\n",dequeue(q));
    printf("Item Deleted:%d\n",dequeue(q));
    // printf("%d\n",dequeue(q));
    // printf("%d\n",dequeue(q));
    // printf("%d\n",dequeue(q));
    // printf("%d\n",dequeue(q));
    // // printf("Rear:%d\n",q->rear);
    // printf("Front:%d\n",q->front);


    display(q);

    return 0;
}