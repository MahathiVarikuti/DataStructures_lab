#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int dist[MAX];  // Shortest distances from source
bool visited[MAX];  // Visited vertices
int operationCount = 0;

void dijkstra(int graph[MAX][MAX], int n, int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;  // Initialize distances as infinity
        visited[i] = false;  // Mark all vertices as unvisited
    }
    dist[source] = 0;  // Distance to source is 0

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum distance
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
            operationCount++;  // Counting the comparison operation
        }

        visited[u] = true;  // Mark the selected vertex as visited

        // Update the distance for all adjacent vertices of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != -1 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                operationCount++;  // Counting the update operation
            }
        }
    }

    // Print the results
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
    printf("Total Operations: %d\n", operationCount);
}

int main() {
    int n, source;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (-1 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);
    return 0;
}
