#include <stdio.h>
#include <stdlib.h>

// Circular Linked List Using Tail

typedef struct node{
    int data;
    struct node* next;
}NODE;



NODE* getNode(int data){
    NODE* last = (NODE*)malloc(sizeof(NODE));

    if(last==NULL){
        printf("Memory Allocation failed\n");
        return last;
    }
    last->data=data;
    last->next=last;

    return last;
}

NODE* insertion_front(NODE* last,int data){
    NODE* new = getNode(data);
    if(last==NULL){
        return new;
    }
    new->next=last->next;
    last->next=new;

    return last;
}



NODE* insertion_end(NODE* last,int data){
    NODE* new = getNode(data);

    if(last==NULL){
        return new;
    }

    new->next=last->next;
    last->next=new;
    last=new;

    return last;
}



NODE* insertion_pos(NODE* last,int data,int pos){
    NODE* new = getNode(data);

    if(pos==1){
        return insertion_front(last,data);
    }
    if(pos<=0){
        printf("Invalid Position\n");
        return last;
    }

    int count = 1;
    NODE* ptr = last->next;

    while(ptr!=last && count < pos-1 ){
            ptr=ptr->next;
            count++;
    }
    if(ptr==last){
        return insertion_end(last,data);
    }
    

    new->next=ptr->next;
    ptr->next=new;

    return last;
}

NODE* deletion_front(NODE* last){
    if(last==NULL){
        printf("Empty List\n");
        return last;
    }

    NODE* ptr = last->next;

    if(ptr==last){
        printf("Item Deleted:%d\n",ptr->data);
        free(ptr);
        return NULL;
    }

    last->next=ptr->next;

    printf("Item Deleted:%d\n",ptr->data);
    free(ptr);


    return last;


}



NODE* deletion_last(NODE* last){
    if(last==NULL){
        printf("Empty List\n");
        return last;
    }
    if(last->next==last){
        return deletion_front(last);
    }

    NODE* ptr = last->next;

    while(ptr->next!=last){
       ptr=ptr->next;
    }

    ptr->next=last->next;
    printf("Item Deleted:%d\n",last->data);
    free(last);

    last=ptr;

    return last;
}

NODE* deletion_pos(NODE* last,int pos){
    if(pos==1){
        return deletion_front(last);
    }
    if(pos<=0){
        printf("Invalid Position\n");
        return last;
    }

    int count = 1;
    NODE* ptr = last->next;
    NODE* prev = NULL;

    while(ptr!=last && count < pos){
        prev=ptr;
        ptr=ptr->next;
        count++;
    }
    if(ptr==last){
        return deletion_last(last);
    }

    prev->next=ptr->next;

    printf("Item Deleted:%d\n",ptr->data);
    free(ptr);

    return last;


}





NODE* display(NODE* last){
    if(last==NULL){
        printf("Empty List\n");
        return last;
    }

    NODE* ptr = last->next;

    printf("%d|",ptr->data);

    while(ptr!=last){
         ptr=ptr->next;
         printf("%d|",ptr->data);
    }

    return last;
}


// Main function for verification 
// For Menu Driven look up to SinglyLinkedList



int main(){

    NODE* last=NULL;

    last = insertion_front(last,15);
    last = insertion_front(last,25);
    last = insertion_front(last,35);
    last = insertion_end(last,5);
    last = deletion_last(last);
    last= insertion_pos(last,22,3);
    // last = deletion_pos(last,2);
    // last = deletion_pos(last,3);

    display(last);

    return 0;
}
