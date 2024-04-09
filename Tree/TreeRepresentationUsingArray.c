#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 50


typedef struct tree{
    int arr[MAXSIZE];
    int index;  // index to track where do we need to insert next value
}TREE;

TREE* initialiseTree(){
    TREE* tree = (TREE*)malloc(sizeof(TREE));
    
    if(tree==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }
    
    tree->index=1; // index starting from 1
    
    for(int i=0;i<MAXSIZE;i++){  // initialise array with -1 
        tree->arr[i]=-1;
    }
    
    return tree;
    
    
}

void insert(TREE* tree,int data){
    if(tree==NULL){
        printf("Tree is Null");
        exit(0);
    }
    
    tree->arr[tree->index++]=data;
    
    
}

int parent(TREE* tree,int index){
    if(tree==NULL){
        printf("Tree is Null");
        exit(0);
    }
    
    if(index==1){  // if index is 1 that means it is itself a root 
        printf("Itself a Root\n");
        return -1;
    }
    
    return tree->arr[(int)floor(index/2)];
}

int leftChild(TREE* tree, int index){
    if(tree==NULL){
        printf("Tree is Null\n");
        exit(0);
    }
    
    if(index * 2 >= tree->index || tree->arr[index * 2] == -1){  
        printf("There is no left child of this node\n");
        return -1;
    }
    
    return tree->arr[index * 2];
}



int rightChild(TREE* tree, int index){
    if(tree==NULL){
        printf("Tree is Null\n");
        exit(0);
    }
    
    if(index * 2 + 1 >= tree->index || tree->arr[index * 2 + 1] == -1){
        printf("There is no right child of this node\n");
        return -1;
    }
    
    return tree->arr[index * 2 + 1];
}


void search(TREE* tree,int data){
    for(int i=1;i<tree->index;i++){
        if(data==tree->arr[i]){
            printf("Element found\n");
            if(parent(tree,i)!=-1)printf("Parent Element:%d\n",parent(tree,i));  // if parent returns -1 that means it is a root element
            // If child returns -1 that means there is no child of the given value
            if(leftChild(tree,i)!=-1) printf("Left Child:%d\n",leftChild(tree,i)); 
            if(rightChild(tree,i)!=-1) printf("Right Child:%d\n",rightChild(tree,i));
            
        }
    }
}

void display(TREE* tree){
    for(int i=1;i<tree->index;i++){
        printf("%d->",tree->arr[i]);
    }
    printf("\n");
}


int main(){
    int choice,data;
    TREE* tree = initialiseTree();
    
    while(1){
        printf("1.Insert\n2.Search\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        
        if(choice==1){
            printf("Enter data:");
            scanf("%d",&data);
            insert(tree,data);
        }
        else if(choice==2){
            printf("Enter data:");
            scanf("%d",&data);
            search(tree,data);
        }
        else if(choice==3){
            display(tree);
        }
        else if(choice==4){
            break;
        }
        else{
            printf("Invalid Input");
        }
        
        
        
    }
    
    
    
    return 0;
}




