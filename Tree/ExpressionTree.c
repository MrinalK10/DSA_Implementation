#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}NODE;

NODE* getNode(char data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    if(newNode == NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

NODE* expressionTree(char ch[]) {
    int i = 0;
    NODE* stack[SIZE];
    int top = -1;

    while (ch[i] != '\0') {
        NODE* newNode = NULL;
        NODE* a = NULL;
        NODE* b = NULL;

        switch (ch[i]) {
            case '^':
            case '/':
            case '*':
            case '-':
            case '+':
                if (top < 1) {
                    printf("Invalid expression\n");
                    exit(1);
                }
                a = stack[top--];
                b = stack[top--];
                newNode = getNode(ch[i]);
                newNode->right = a;
                newNode->left = b;
                stack[++top] = newNode;
                break;

            case 'A'...'Z':
            case 'a'...'z':
            case '0'...'9':
                newNode = getNode(ch[i]);
                stack[++top] = newNode;
                break;

            default:
                printf("Invalid character in expression\n");
                exit(1);
        }

        i++;
    }

    if (top != 0) {
        printf("Invalid expression\n");
        exit(1);
    }

    return stack[0]; // Return the root of the expression tree
}

int isOperator(char ch){
    if (ch=='+' || ch=='-'||ch=='*'||ch=='/'||ch=='^') return 1;

    return 0;
}

int evaluateExpressionTree(NODE* root){
    if(root == NULL) return 0;
    if(!isOperator(root->data)) return root->data - '0';

    int left_val = evaluateExpressionTree(root->left);
    int right_val = evaluateExpressionTree(root->right);

    switch(root->data){
            case '/': return left_val/right_val;
            case '*': return left_val*right_val;
            case '-': return left_val-right_val;
            case '+': return left_val+right_val;
    }

    return 0;
}


void inorder(NODE* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}

void preorder(NODE* root){
    if(root!=NULL){
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);
    }
}

int main(){

    char ch[20] = "12+34+*";

    NODE* et = expressionTree(ch);

    inorder(et);
    printf("\n");
    preorder(et);
    printf("\n");
    postorder(et);
    printf("\n");

    printf("%d",evaluateExpressionTree(et));

    

    return 0;
}