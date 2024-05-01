#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct Graph{
    int numVertices;
    int ** adjacencyMatrix;
    int* visited;
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

    graph->visited=(int*)malloc(sizeof(int)*vertices);


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

void dfs(GRAPH* graph,int vertex){
    graph->visited[vertex]=1;
    printf("%d-",vertex);

    for(int i=0;i<graph->numVertices;i++){
        if(graph->adjacencyMatrix[vertex][i]==1 && graph->visited[i]==0){
            dfs(graph,i);
        }
    }

}

void dfsTraversal(GRAPH* graph){
    for(int i=0;i<graph->numVertices;i++){
        graph->visited[i]=0;

    }

    for(int i=0;i<graph->numVertices;i++){
        if(!graph->visited[i]){
            dfs(graph,i);
        }
    }


}

void bfs(GRAPH* graph,int vertex){
    graph->visited[vertex]=1;
    int QUEUE[max];
    int front=0;
    int rear=0;

    QUEUE[rear++]=vertex;

    while(front!=rear){
        int currentVertex = QUEUE[front++];
        printf("%d-",currentVertex);
        for(int i=0;i<graph->numVertices;i++){
            if(graph->visited[i]==0 && graph->adjacencyMatrix[currentVertex][i]==1){
                QUEUE[rear++]=i;
                graph->visited[i]=1;
            }
            
        }

        
        
    }

}

void bfsTraversal(GRAPH* graph){
    for(int i=0;i<graph->numVertices;i++){
        graph->visited[i]=0;

    }

    for(int i=0;i<graph->numVertices;i++){
        if(!graph->visited[i]){
            bfs(graph,i);
        }
    }


}

int main(){

    GRAPH* graph =createGraph(8);

    addEdge(graph,0,4);
    addEdge(graph,4,6);
    addEdge(graph,6,2);
    addEdge(graph,6,5);
    addEdge(graph,6,7);
    addEdge(graph,5,7);
    addEdge(graph,2,1);
    addEdge(graph,3,1);
   
    // printEdge(graph);

    // dfsTraversal(graph);
    bfsTraversal(graph);
    
    
    return 0;
}