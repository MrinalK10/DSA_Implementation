#include <stdio.h>
#define TableSize 12

void initializeTable(int arr[])
{
    for (int i = 0; i < TableSize; i++)
    {
        arr[i] = -1;
    }
}

int hashFunction(int key)
{
    return key % TableSize;
}

void insert(int key, int table[])
{
    int index = hashFunction(key);
    int start_index = index;
    while (table[index] != -1)
    {
        index = (index + 1) % TableSize;
        if (index == start_index)
        {
            printf("Hash Table is Full\n");
            return;
        }
    }
    table[index] = key;
    printf("%d is inserted at %d index\n", key, index);
}

int search(int key, int table[])
{
    int index = hashFunction(key);
    int start_index = index;
    while (table[index] != -1)
    {
        if (table[index] == key)
        {
            printf("%d found at %d\n",key, index);
            return index;
        }
        index = (index + 1) % TableSize;
        if (index == start_index)
        {
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n");
    return -1;
}

// -1 for null and -2 for delete

void delete(int key,int table[]){
    int index = search(key,table);
    if (index != -1){
        table[index] = -2;
        printf("%d deleted from index %d\n",key,index);
    }
    else{
        printf("Key not found\n");
    }

}


int main()
{
    int table[12];
    initializeTable(table);
    int flag = 1;
    int key;

    insert(4,table);
    insert(16,table);
    insert(9,table);
    insert(21,table);
    insert(3,table);
    insert(15,table);
    insert(7,table);
    insert(19,table);
    insert(1,table);
    insert(13,table);
    search(19,table);
    search(2,table);
    delete(19,table);
    for (int i = 0; i < TableSize; i++)
    {
        printf("%d ", table[i]);
    }

    return 0;
}
