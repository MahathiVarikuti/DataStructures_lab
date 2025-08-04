#include <stdio.h>

int graph[100][100];      // Adjacency matrix
int visited[100];         // Visited array
int stack[100];           // Stack to store topological order
int top = -1;             // Stack top pointer
int opcount = 0;          // Operation count

void DFS(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        opcount++;  // Count operation per adjacency check
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
    stack[++top] = v;  // Push to stack after exploring all adjacent
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter the edges (from to):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    // Call DFS for all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n);
        }
    }

    // Output topological sort
    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    printf("\nOperation Count: %d\n", opcount);
    return 0;
}
