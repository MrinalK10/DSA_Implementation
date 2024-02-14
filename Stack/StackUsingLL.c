#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* getNode (int data){

    NODE* new = (NODE*)malloc(sizeof(NODE));

    if(new==NULL){
        printf("Memory Allocation Failed\n");
        exit(0);
    }

    new->data=data;
    new->next=NULL;

    return new;
}

int isEmpty(NODE* start){
    return start==NULL;
}

NODE* push(NODE* start,int data){
     
     NODE* new = getNode(data);
     
    if(isEmpty(start)){
        return new;
    }

    new->next=start;
    start=new;

    return start;

}

// Double pointer because we are changing the actual start which is stored in particular address and returning item

int pop(NODE** start){
    if(isEmpty(*start)){
        printf("Empty Stack\n");
        return -1;
    }

    NODE* ptr = *start;
    *start=(*start)->next;
    int item = ptr->data;
    free(ptr);

    return item;
}



int peek(NODE* start){
    if(isEmpty(start)){
        printf("Empty Stack\n");
        return -1;
    }
    return start->data;
}

void display(NODE* start){
    NODE* ptr = start;
    
    if(isEmpty(start)){
        printf("Empty Stack\n");
        return ;
    }

    printf("Stack:");

    while(ptr!=NULL){
        printf("%d|",ptr->data);
        ptr=ptr->next;
    }

    

}

// Main function for verification 
// For Menu Driven look up to SinglyLinkedList



int main(){

    NODE* start = NULL;

    start = push(start,15);
    start = push(start,25);
    start = push(start,35);

    printf("Item Deleted:%d\n",pop(&start));
    printf("Top of the stack:%d\n",peek(start));

    display(start);



    return 0;
}



