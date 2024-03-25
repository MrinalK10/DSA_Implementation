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
    // graph->adjacencyMatrix[dest][src]=1;
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

void warshalls(int** adjacencyMatrix, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjacencyMatrix[i][j] = adjacencyMatrix[i][j] || (adjacencyMatrix[i][k] && adjacencyMatrix[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    GRAPH* graph=createGraph(4);
    
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,3,1);

    // printEdge(graph);
   

    warshalls(graph->adjacencyMatrix,4);


    freegraph(graph);




    return 0;
}