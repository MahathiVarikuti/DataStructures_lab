#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];
int operationCount = 0;

int find(int i) {
    operationCount++;
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_sets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int n, int e) {
    Edge result[MAX];
    int i, j = 0, totalWeight = 0;

    qsort(edges, e, sizeof(Edge), compare);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e && j < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            result[j++] = edges[i];
            totalWeight += edges[i].weight;
            union_sets(u, v);
        }
        operationCount++;
    }

    printf("\nEdges in MST:\n");
    for (i = 0; i < j; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);

    printf("\nTotal Cost = %d\n", totalWeight);
    printf("Total Operations = %d\n", operationCount);
}

int main() {
    int n, e;
    Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, n, e);
    return 0;
}
