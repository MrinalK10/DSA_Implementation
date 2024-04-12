#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* getNode(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    if(newNode==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

NODE* maketree(int data){
    NODE* root = getNode(data);

    return root;
}

// Insertion Using Recursive approach

NODE* insert(NODE* root, int data){
    if(root==NULL){
        return maketree(data);
    }

    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }

    return root;
}

// Insertion Using Iterative approach

NODE* insert2(NODE* root, int data){
    NODE* newNode = getNode(data);
    NODE* temp = root;
    NODE* parent = NULL;

    while(temp!=NULL){
        parent = temp;

        if(temp->data > data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    if(parent == NULL) return newNode;
    else if (parent->data > data) parent->left = newNode;
    else parent->right = newNode;

    return root;

}



// Searching Recursive Approach

NODE* searchItem(NODE* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }

    if(root->data > data){
        return searchItem(root->left,data);
    }
    else{
        return searchItem(root->right,data);
    }
}

// Searching Iterative Approach

int searchItem2(NODE* root, int data){
    NODE* temp = root;

    while(temp!=NULL){
        if(temp->data == data) return 1;
        else if(temp->data > data) temp = temp->left;
        else temp = temp->right;
    }

    return 0;
}

NODE* findLargestNode(NODE* root){
    if (root == NULL) return root;

    if(root->right) return findLargestNode(root->right);
    else return root;
}

NODE* delete(NODE* root, int item){
    if(root == NULL) {
        printf("Item not found in tree\n"); 
        return root;
    }

    if(item < root->data) root->left = delete(root->left,item);
    else if(item > root->data) root->right = delete(root->right,item);
    else{
        if(root->left && root->right){
            NODE* temp = findLargestNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);

        }
        else{
            NODE* temp = root;
            if(root->left==NULL && root->right==NULL) root = NULL;
            else if(root->left!=NULL) root = root->left;
            else root = root->right;
            free(temp);
        }
    }

    return root;
}






void inorder(NODE* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}


int main(){

    NODE* root = maketree(70);
    root = insert(root,50);
    root = insert(root,90);
    root = insert(root,30);
    root = insert(root,60);
    root = insert(root,80);
    root = insert(root,110);

    int data =60;
    if(searchItem2(root,data)) printf("%d Present in the tree\n",data);
    else printf("%d Not present in the tree\n",data);

    root = delete(root,data);

    

    if(searchItem2(root,data)) printf("%d Present in the tree\n",data);
    else printf("%d Not present in the tree\n",data);

    
    

    inorder(root);


    return 0;
}