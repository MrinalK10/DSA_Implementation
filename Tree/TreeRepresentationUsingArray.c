#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree{
    int* arr;
    int count;
} TREE;

TREE* initializeTree(int size){
    TREE* tree = (TREE*)malloc(sizeof(TREE));

    if(tree==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    tree->arr=(int*)malloc(sizeof(int)*size);
     if (tree->arr == NULL) {
        printf("Memory Allocation failed\n");
        free(tree); 
        exit(0);
    }
    tree->count=1;

    for(int i=0;i<size;i++){
        tree->arr[i]=-1;
    }

    return tree;

}

// count taken as 1 because we are putting our first node on the first index

void insert(TREE* tree,int value){

    if(tree==NULL){
        printf("Tree is Null\n");
        return;
    }

    tree->arr[tree->count]=value;
    tree->count++;
}

// Parent Formula : nodePosition / 2 ;

int parent(TREE* tree,int node){

    if(tree==NULL){
        printf("Tree is Empty\n");
        exit(0);
    }

    if(tree->count==2){
        printf("Root Node\n");
        return tree->arr[0];
    }

    return tree->arr[(int)floor(node/2)];

}

// LeftChild Formula : 2 * Node Position

int leftChild(TREE* tree, int node){
    if(tree==NULL){
        printf("Tree is Empty\n");
        exit(0);
    }

    int leftChild = tree->arr[2*node];

    if(leftChild==-1){
        printf("There is no left child of this node\n");
        exit(0);
    }

    return leftChild;
}

// RightChild Formula : 2 * Node Position + 1 

int rightChild(TREE* tree, int node){
    if(tree==NULL){
        printf("Tree is Empty\n");
        exit(0);
    }

    int rightChild = tree->arr[2*node+1];

    if(rightChild==-1){
        printf("There is no right child of this node\n");
        exit(0);
    }

    return rightChild;
}

void print(TREE* tree){
    for(int i=1;i<tree->count;i++){
        printf("%d|",tree->arr[i]);
    }
}




int main(){
    TREE* tree = initializeTree(10);
    insert(tree,1);
    insert(tree,2);
    insert(tree,3);
    insert(tree,4);
    insert(tree,5);

    printf("Parent of 2:%d\n",parent(tree,2));
    printf("Left Child of 1:%d\n",leftChild(tree,1));
    printf("Right Child of 1:%d\n",rightChild(tree,1));

    print(tree);

    return 0;
    

}