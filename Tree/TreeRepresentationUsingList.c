#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* createNode(int data){
    NODE* new = (NODE*)malloc(sizeof(NODE));

    if(new==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    new->data=data;

    new->left=NULL;
    new->right=NULL;

    return new;
}

NODE* maketree(int data){
    NODE* root = createNode(data);
    return root;
}

NODE* insert(NODE* root, int data){

    if(root==NULL){
        return maketree(data);
    }

    NODE* newNode = createNode(data);

    NODE* queue[SIZE];
    int front=0;
    int rear=0;

    queue[rear++] = root;

    while(front<rear){
        NODE* current = queue[front++];

        if(current->left == NULL){
            current->left = newNode;
            return root;
        }
        else{
            queue[rear++]=current->left;
        }

        if(current->right == NULL){
            current->right = newNode;
            return root;
        }
        else{
            queue[rear++]=current->right;
        }


    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findDepth(NODE* root) {
    if (root == NULL)
        return 0;
    else 
        return 1 + max(findDepth(root->left),findDepth(root->right ));
    
}

void postOrder(NODE* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d->",root->data);
    }
}
   

void preOrder(NODE* root){
    if(root!=NULL){
        printf("%d->",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

void inorder(NODE* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}




int main(){
    NODE* root = maketree(1);
    root=insert(root,2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    printf("Depth of the tree is: %d\n", findDepth(root));

    printf("PostOrder of tree:");
    postOrder(root);
    printf("\n");
    printf("PreOrder of tree:");
    preOrder(root);
    printf("\n");
    printf("Inorder of tree:");
    inorder(root);
    
    return 0;
}