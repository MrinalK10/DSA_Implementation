#include <stdio.h>
#include <stdlib.h>

// Structure of Node which contains data and pointer to next node 

typedef struct node
{
    int data;
    struct node *next;
} NODE;

// Create a new node 

NODE *getnode(int data)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));

    if (new == NULL)
    {
        printf("Memory Allocation failed\n");
    }
    else
    {
        new->data = data;
        new->next = NULL;
    }

    return new;
}

// Display data of all the Linked List Nodes

NODE *display(NODE *start)
{
    NODE *ptr = start;

    if (ptr == NULL)
    {
        printf("Empty List\n");
        return start;
    }

    while (ptr != NULL)
    {
        printf("%d|", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");

    return start;
}

// Insertion at beginning

NODE *insertion_front(NODE *start, int data)
{
    NODE *new = getnode(data);

    new->next = start;
    start = new;

    return start;
}

// Insertion at end

NODE *insertion_end(NODE *start, int data)
{

    NODE *new = getnode(data);
    NODE *ptr = start;

    if (ptr == NULL)
    {
        return new;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new;

    return start;
}

// Insertion at Particular Position

NODE *insertion_position(NODE *start, int data, int pos)
{
    NODE *new = getnode(data);

    NODE *ptr = start;

    if (pos == 1)
    {
        return insertion_front(start, data);
    }

    if (pos < 1)
    {
        printf("Invalid Position\n");
        return start;
    }

    int count = 1;

    while (ptr != NULL && count < pos - 1)
    {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL)
    {
        printf("Invalid Position\n");
        return start;
    }

    new->next = ptr->next;
    ptr->next = new;

    return start;
}

// Insertion at correct order if sorted

NODE *insertion_order(NODE *start, int data)
{
    NODE *new = getnode(data);
    NODE *ptr = start;
    NODE *prev = NULL;

    if (ptr == NULL)
    {
        insertion_front(start, data);
    }

    if (new->data < ptr->data)
    {
        insertion_front(start, data);
    }

    while (ptr != NULL && new->data > ptr->data)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    
    prev->next = new;
    new->next = ptr;

    return start;
}

// Deletion from beginning

NODE *deletion_front(NODE *start)
{
    NODE *ptr = start;

    int item = ptr->data;

    printf("Item Deleted:%d\n", item);

    start = start->next;

    free(ptr);

    return start;
}

// Deletion from end

NODE *deletion_end(NODE *start)
{

    NODE *ptr = start;
    NODE *prev = NULL;
    if (ptr == NULL)
    {
        printf("Empty List\n");
        return start;
    }

    if (start->next == NULL)
    {
        deletion_front(start);
    }

    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;

    int item = ptr->data;

    printf("Item Deleted:%d\n", item);

    free(ptr);

    return start;
}

// Deletion from particular position

NODE *deletion_pos(NODE *start, int pos)
{

    NODE *ptr = start;
    NODE *prev = NULL;

    if (ptr == NULL)
    {
        printf("Empty List\n");
        return start;
    }

    if (pos == 1)
    {
        deletion_front(start);
    }

    if (pos < 1)
    {
        printf("Invalid Position\n");
        return start;
    }

    int count = 1;

    while (ptr != NULL && count < pos)
    {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL)
    {
        printf("Invalid Position\n");
        return start;
    }

    prev->next = ptr->next;

    int item = ptr->data;

    printf("Item Deleted:%d\n", item);

    free(ptr);

    return start;
}

// Delete a Particular Value

NODE *deletion_value(NODE *start, int value)
{
    NODE *ptr = start;
    NODE *prev = NULL;

    if (ptr == NULL)
    {
        printf("Empty List\n");
        return start;
    }

    // Special case: deleting the first node
    if (ptr->data == value)
    {
        start = deletion_front(start);
        return start;
    }

    while (ptr != NULL && ptr->data != value)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Data Not Found\n");
        return start;
    }

    prev->next = ptr->next;

    int item = ptr->data;

    printf("Item Deleted:%d\n", item);

    free(ptr);

    return start;
}

// Reverse the list

NODE* reverseLL(NODE* start){
    NODE* prev = NULL;
    NODE* next =NULL;

    while(start!=NULL){

    next = start->next;
    start->next = prev;
    prev= start;
    start=next;

    }

    start=prev;


    return start;



}


int main()
{

    NODE *start = NULL;

    int choice, choice2, data, pos, status;

    while (1)
    {
        printf("Press 1 for insertion 2 for deletion 3 for exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("1.Insertion from front\n2.Insertion from End\n3.Insertion from particular position\n4.Insertion in order\n5.Exit\n");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                printf("Enter the data:\n");
                scanf("%d", &data);
                start = insertion_front(start, data);
                display(start);
                break;
            case 2:
                printf("Enter the data:\n");
                scanf("%d", &data);
                start = insertion_end(start, data);
                display(start);
                break;
            case 3:
                printf("Enter the data:\n");
                scanf("%d", &data);
                printf("Enter position you want to insert:\n");
                scanf("%d", &pos);
                start = insertion_position(start, data, pos);
                display(start);
                break;
            case 4:
                printf("Enter the data:\n");
                scanf("%d", &data);
                insertion_order(start, data);
                display(start);
                break;
            default:
                printf("Invalid Input");
            }
        }

        else if (choice == 2)
        {
            printf("1.Deletion from front\n2.Deletion from end\n3.Deletion from particular position\n4.Deletion from value\n5.Exit\n");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                start = deletion_front(start);
                display(start);
                break;

            case 2:
                start = deletion_end(start);
                display(start);
                break;
            case 3:
                printf("Enter position you want to delete:\n");
                scanf("%d", &pos);
                start = deletion_pos(start, pos);
                display(start);
                break;
            case 4:
                printf("Enter the value:\n");
                scanf("%d", &data);
                start = deletion_value(start, data);
                display(start);
                break;

            default:
                printf("Invalid Input\n");
            }
        }
        else
        {
            printf("Invalid Input");
        }

        printf("Do you want to continue 1 to continue 2 to exit\n");
        scanf("%d", &status);

        if (status == 2)
        {
            break;
        }

        else if (status == 1)
        {
            continue;
        }

        else
        {
            printf("Invalid Output\n");
            break;
        }
    }

    return 0;
}