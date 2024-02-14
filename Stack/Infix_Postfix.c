#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    struct node* next;
}NODE;

NODE* getNode (char data){

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

void push(NODE** start,int data){
     
     NODE* new = getNode(data);
     
    

    new->next=*start;
    *start=new;

    

}

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

int peek(NODE** start){
    if(isEmpty(*start)){
        printf("Empty Stack\n");
        return -1;
    }
    return (*start)->data;
}

void display(NODE* start){
    NODE* ptr = start;
    
    if(isEmpty(start)){
        printf("Empty Stack\n");
        return ;
    }

    while(ptr!=NULL){
        printf("%d|",ptr->data);
        ptr=ptr->next;
    }

    

}

int precedence(char ch){
    switch(ch){
        case '^':
        case '$': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;

    
    }

    return 0;
}

char* postfix(char ch[]){
    
    NODE* start = NULL;

    

    char* postfix=(char*)malloc(sizeof(char)*50);
    int j=0;


    for(int i=0;i<strlen(ch);i++){
        char symbol = ch[i];

        switch(symbol){
            case '(':
            case '^':
            case '$': push(&start,symbol); break;
            case '/':
            case '*':
            case '+':
            case '-':  while(!isEmpty(start) && precedence(symbol)<=precedence(peek(&start))){
                         
                         postfix[j++]=pop(&start);
                       
                       }

                       push(&start,symbol);break;
            case ')': while(!isEmpty(start) && peek(&start)!='('){
                      postfix[j++]=pop(&start);
            }
             
             pop(&start);break;
            case 'A'...'Z':
            case 'a'...'z':
            case '0'...'9': postfix[j++]=symbol;



        }
    }

      while(!isEmpty(start)){
        postfix[j++]=pop(&start);
      }

      postfix[j]='\0';

      return postfix;


}

int main(){

    char ch[50]="( A + B ) * C - ( D - E ) * ( F + G )";
    // 'A B + C * D E - F G + * -'


    printf("Infix:%s\n",ch);
    printf("Postfix:%s",postfix(ch));






}