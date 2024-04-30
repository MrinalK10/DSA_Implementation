#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

void initializeTable(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = -1;
    }
}

int hashFunction(int key){
    return key%SIZE;
}



void insert(int key,int table[]){
    int index = hashFunction(key);
    int i=0;

    while(table[index]!=-1){
        i++;
        index = (index + i*i)%SIZE;

        if(i==SIZE){
            printf("Hash Table is Full\n");
            return;
        }
    }
    table[index]=key;
    printf("%d is inserted at %d index\n", key, index);
}

int search(int key,int table[]){
    int index = hashFunction(key);
    int i=0;
    while(table[index]!=-1){

         if (table[index] == key)
        {
            printf("%d found at %d\n",key, index);
            return index;
        }

        i++;
        index = (index+i*i)%SIZE;

         if(i==SIZE){
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n");
    return -1;
}

void delete(int key,int table[]){
    int index = search(key,table);
    if(index!=-1){
        table[index]=-2;
        printf("%d deleted from index %d\n",key,index);
    }
    else{
        printf("Key not found\n");
    }
}

int main(){
    int table[SIZE];
    initializeTable(table);
    insert(14,table);
    insert(28,table);
    insert(22,table);
    insert(32,table);
    insert(41,table);
    insert(58,table);
    insert(62,table);
    insert(89,table);
    insert(17,table);
    insert(99,table);
    insert(45,table);

    delete(45,table);

    search(32,table);
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", table[i]);
    }
}