#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int numVertices;
    int ** adjacencyMatrix;
}GRAPH;

GRAPH* createGraph(int vertices){
    GRAPH* graph=(GRAPH*)malloc(sizeof(GRAPH));

    if(graph==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }
    graph->numVertices=vertices;
    graph->adjacencyMatrix=(int**)malloc(vertices*sizeof(int*));

    if(graph->adjacencyMatrix==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    for(int i=0;i<vertices;i++){
        graph->adjacencyMatrix[i]=(int*)malloc(vertices*sizeof(int));

        if(graph->adjacencyMatrix[i]==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }
        for(int j=0;j<vertices;j++){
            graph->adjacencyMatrix[i][j]=0;
        }

    }

    return graph;
}

void addEdge(GRAPH* graph,int src,int dest){
    graph->adjacencyMatrix[src][dest]=1;
    graph->adjacencyMatrix[dest][src]=1;
}

void printEdge(GRAPH* graph){
    for(int i=0;i<graph->numVertices;i++){
        for(int j=0;j<graph->numVertices;j++){
            printf("%d ",graph->adjacencyMatrix[i][j]);
    }
        printf("\n");
    }
}

void freegraph(GRAPH* graph){
    for(int i=0;i<graph->numVertices;i++){
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main(){

    GRAPH* graph=createGraph(5);
    
    addEdge(graph,2,1);

    printEdge(graph);




    return 0;
}