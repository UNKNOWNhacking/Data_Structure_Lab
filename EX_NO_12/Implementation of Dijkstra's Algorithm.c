#include <stdio.h>
#define INF 9999
#define MAX 10

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start);

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) {
    int cost[MAX][MAX], distance[MAX], previous[MAX];
    int visited_nodes[MAX], counter, minimum_distance, next_node, i, j;

    // Initialize the cost matrix
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (Graph[i][j] == 0) {
                cost[i][j] = INF;
            } else {
                cost[i][j] = Graph[i][j];
            }
        }
    }

    // Initialize distances and visited nodes
    for (i = 0; i < size; i++) {
        distance[i] = cost[start][i];
        previous[i] = start;
        visited_nodes[i] = 0;
    }

    distance[start] = 0;
    visited_nodes[start] = 1;
    counter = 1;

    // Main loop of Dijkstra's Algorithm
    while (counter < size - 1) {
        minimum_distance = INF;

        // Find the next node with the smallest distance
        for (i = 0; i < size; i++) {
            if (distance[i] < minimum_distance && !visited_nodes[i]) {
                minimum_distance = distance[i];
                next_node = i;
            }
        }

        visited_nodes[next_node] = 1;

        // Update the distances of the adjacent nodes
        for (i = 0; i < size; i++) {
            if (!visited_nodes[i]) {
                if (minimum_distance + cost[next_node][i] < distance[i]) {
                    distance[i] = minimum_distance + cost[next_node][i];
                    previous[i] = next_node;
                }
            }
        }
        counter++;
    }

    // Print the results
    for (i = 0; i < size; i++) {
        if (i != start) {
            printf("\nDistance from the Source Node to %d: %d", i, distance[i]);
        }
    }
}

int main() {
    int Graph[MAX][MAX], i, j, size, source;

    size = 7;

    // Initialize the graph
    int graph_data[7][7] = {
        {0, 4, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0},
        {0, 0, 7, 0, 9, 14, 0},
        {0, 0, 0, 9, 0, 10, 2},
        {0, 0, 4, 14, 10, 0, 2},
        {0, 0, 0, 0, 2, 2, 1}
    };

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            Graph[i][j] = graph_data[i][j];
        }
    }

    source = 0;
    DijkstraAlgorithm(Graph, size, source);

    return 0;
}
