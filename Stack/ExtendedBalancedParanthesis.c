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

NODE* push(NODE* start,char data){
     
     NODE* new = getNode(data);
     
    if(isEmpty(start)){
        return new;
    }

    new->next=start;
    start=new;

    return start;

}

char pop(NODE** start){
    if(isEmpty(*start)){
        printf("Empty Stack\n");
        exit(0);
    }

    NODE* ptr = *start;
    *start=(*start)->next;
    char item = ptr->data;
    free(ptr);

    return item;
}

char peek(NODE* start){
    if(isEmpty(start)){
        printf("Empty Stack\n");
        exit(0);
    }
    return start->data;
}

int checkpair(char ch1,char ch2){
    if(ch1=='(' && ch2==')') return 1;
    else if(ch1=='[' && ch2==']') return 1;
    else if(ch1=='{' && ch2=='}') return 1;

    return 0;
}


int isValidParanthesis(char ch[]){

   NODE* start=NULL;

   for(int i=0;i<strlen(ch);i++){

      if(ch[i]=='('||ch[i]=='{'||ch[i]=='['){
        start=push(start,ch[i]);
      }
      else{
        if(isEmpty(start)){
            return 0;
        }

        char ele = pop(&start);

        if(!checkpair(ele,ch[i])){
            return 0;
        }

    }

      
   }

   if(!isEmpty(start)){
        return 0;
      }

      return 1;



}



int main(){

    char ch[10]="{([])}";

    if(isValidParanthesis(ch)){
        printf("Balanced Paranthesis");
    }

    else{
        printf("Not an Balanced Paranthesis");
    }




    return 0;
}