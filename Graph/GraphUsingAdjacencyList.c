#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int vertex;
    struct node* next;
}NODE;

NODE* createNode(int vertex){
    NODE* new = (NODE*)malloc(sizeof(NODE));

    if(new==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }
    new->vertex=vertex;
    new->next=NULL;

    return new;
}

NODE *insertion_front(NODE *start, int data)
{
    NODE *new = createNode(data);

    new->next = start;
    start = new;

    return start;
}



int numVertices;
NODE** adjacencyList;




void initializeGraph(int vertex){

 numVertices=vertex;
 adjacencyList=(NODE**)malloc(vertex*sizeof(NODE*));

 for(int i=0;i<vertex;i++){
    adjacencyList[i]=NULL;
 }

}

void addEdge(int src, int dest) {
    adjacencyList[src] = insertion_front(adjacencyList[src], dest);
    adjacencyList[dest] = insertion_front(adjacencyList[dest], src);
}

void printEdge(){
    for(int i=0;i<numVertices;i++){
        NODE* temp=adjacencyList[i];
        printf("Vertex %d",i);
        while(temp){
            printf("->%d",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){

    initializeGraph(5);
    addEdge(1,2);
    addEdge(1,4);
    addEdge(4,2);

    printEdge();



    return 0;
}


