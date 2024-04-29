#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* getNode(int data){
    NODE* new = (NODE*)malloc(sizeof(NODE));

    if(new==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }
    new->data=data;
    new->next=NULL;

    return new;
}

NODE* hashTable[SIZE];

void initializeTable(){
    for(int i=0;i<SIZE;i++){
        hashTable[i]=NULL;
    }
}

int hashFunction(int key){
    return key%SIZE;
}

void insert(int key){

    NODE* newNode = getNode(key);

    int index = hashFunction(key);


    if(hashTable[index]==NULL){
        hashTable[index]=newNode;
        
    }
    else{
        NODE* temp = hashTable[index];
        while(temp->next){
            temp=temp->next;
        }
        temp->next = newNode;
    }

}

void search(int key){
    int index = hashFunction(key);
    NODE* temp = hashTable[index];

    while(temp){
        if(key==temp->data) {
            printf("Key found\n");
            return;
        }

        temp=temp->next;
    }

    printf("Key not found\n");

}

void delete(int key){
    int index = hashFunction(key);
    NODE* temp = hashTable[index];
    NODE* prev = NULL;

    if(temp->data==key){
        hashTable[index]=hashTable[index]->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not found\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

}

void printHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> ", i);
        NODE* temp = hashTable[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    initializeTable();

    
    insert(5);
    insert(15);
    insert(25);
    insert(7);
    insert(17);
    insert(27);

    
    printHashTable();

    
    search(15);

    
    delete(15);

   
    printHashTable();

    return 0;
}

