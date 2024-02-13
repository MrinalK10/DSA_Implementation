#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}NODE;

NODE* getNode(int data){
    NODE* new = (NODE*) malloc(sizeof(NODE));

    if(new==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    new->data=data;
    new->next=NULL;
    new->prev=NULL;

    return new;
}

NODE* insertion_front(NODE* start,int data){
    NODE* new = getNode(data);
    
    if(start!=NULL){
    new->next = start;
    start->prev = new ;
    }  
    start = new;

    return start;
}

NODE* insertion_last(NODE* start,int data){
    if(start==NULL){
        printf("Empty List\n");
        return start;
    }
    NODE* new = getNode(data);
    NODE* ptr = start;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    new->prev=ptr;
    ptr->next=new;

    return start;

}

NODE* insertion_pos(NODE* start,int data,int pos){
    NODE* new = getNode(data);
    
    if(pos==1){
        start = insertion_front(start,data);
        return start;
    }

    if(pos<=0){
        printf("Invalid Position\n");
        return start;
    }

    int count=1;
    NODE* ptr = start;

    while(ptr!=NULL && count < pos -1 ){
        ptr=ptr->next;
        count++;
    }
    if(ptr==NULL){
        printf("Invalid Position\n");
        return start;
    }
    if(ptr->next==NULL){
        start = insertion_last(start,data);
        return start;
    }
    else{
        new->next=ptr->next;
        new->prev=ptr;
        ptr->next=new;

        
        ptr=new->next;
        ptr->prev=new;
        

        return start;
    }



}

NODE* insert_order(NODE* start,int data){
    NODE* new = getNode(data);

    if(start==NULL || new->data < start->data){
        return insertion_front(start,data);
    }

    NODE* ptr = start;
    NODE* prev = NULL;

    while(ptr!=NULL && new->data > ptr->data){
        
        ptr=ptr->next;
    }

    if(ptr==NULL){
        return insertion_last(start,data);
    }
    new->next=ptr;
    new->prev = prev;
    ptr->prev->next = new;
    ptr->prev = new;

    return start;


}



NODE* deletion_front(NODE* start){
    if(start==NULL){
        printf("Empty List\n");
        return start;
    }

   if(start->next==NULL){
       printf("Item Deleted:%d\n",start->data);
       free(start);
       return NULL;
   }

   NODE* ptr = start;
   start=start->next;
   start->prev=NULL;
   printf("Item Deleted:%d\n",ptr->data);
   free(ptr);

   return start;

    

}

NODE* deletion_last(NODE* start){
    if(start==NULL){
        printf("Empty List\n");
        return start;
    }
    if(start->next==NULL){
        start=deletion_front(start);
        return start;
    }

    NODE* ptr = start;
    

    while(ptr->next!=NULL){
        
        ptr=ptr->next;
    }

    ptr->prev->next=NULL;

    printf("Item Deleted:%d\n",ptr->data);
    free(ptr);

    return start;

}


NODE* deletion_pos(NODE* start,int pos){
    
     if(start==NULL){
        printf("Empty List\n");
        return start;
     }

     if(pos==1){
        start = deletion_front(start);
        return start;
     }

     if(pos<=0){
        printf("Invalid Position\n");
        return start;
     }

     NODE* ptr = start;
     

     int count=1;

     while(ptr!=NULL && count < pos){
        ptr=ptr->next;
        count++;
     }

     if(ptr==NULL){
        printf("Invalid Position\n");
        return start;
     }

     if(ptr->next==NULL){
        start = deletion_last(start);
        return start;
     }
     
     else{
          ptr->prev->next=ptr->next;
          ptr->next->prev=ptr->prev;
          printf("Item Deleted:%d\n",ptr->data);
          free(ptr);
          return start;
     }


}



NODE* display(NODE* start){
    NODE* ptr = start;

    if(start==NULL){
        printf("Empty List\n");
        return start ;
    }

    while(ptr!=NULL){
        printf("%d|",ptr->data);
        ptr=ptr->next;
    }

    printf("\n");

    return start;
}

int countNode(NODE* start){
    NODE* ptr = start;
    int count = 0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }

    return count;
}

NODE* reverse(NODE* start){
    NODE* ptr = start;
    NODE* next = NULL;
    
    while(ptr!=NULL){
         next=ptr->next;
         ptr->next=ptr->prev;
         ptr->prev=next;
         start = ptr;
         ptr=next;
    }

    
    return start;
}

NODE* sort(NODE* start){
    NODE* ptr = start;
    NODE* ptr1 = start->next;

    while(ptr->next!=NULL){
        while(ptr1!=NULL){
            if(ptr->data>ptr1->data){
                int temp = ptr->data;
                ptr->data=ptr1->data;
                ptr1->data=temp;
                
            }
            ptr1=ptr1->next;
           
        }
         
         ptr=ptr->next;
         ptr1=ptr->next;
    }

    return start;
}



// Main function for verification 
// For Menu Driven look up to SinglyLinkedList


int main(){

    NODE* start = NULL;

    start = insertion_front(start,35);
    start = insertion_front(start,25);
    start = insertion_pos(start,15,1);
    start = insertion_pos(start,45,4);
    start = insertion_pos(start,55,5);
    start = insertion_last(start,65);
    start = deletion_pos(start,6);
    start = insert_order(start,68);
    // start = deletion_last(start);
    // start = deletion_pos(start,3);

    

    display(start);

    start = reverse(start);

    printf("Reversed:\n");

    display(start);


    start = sort(start);

    printf("Sorted:\n");

    printf("count:%d\n",countNode(start));
    
    


    


    return 0;
}