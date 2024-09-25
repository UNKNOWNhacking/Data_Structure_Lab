#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    if (graph->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFSUtil(int v, bool visited[], struct Graph* graph) {
    visited[v] = true;
    printf("%d ", v);
    struct AdjListNode* crawl = graph->array[v].head;
    while (crawl != NULL) {
        int adjVertex = crawl->dest;
        if (!visited[adjVertex])
            DFSUtil(adjVertex, visited, graph);
        crawl = crawl->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool visited[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    DFSUtil(startVertex, visited, graph);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
