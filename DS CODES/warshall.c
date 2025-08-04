#include <stdio.h>
#define MAX 100

int operationCount = 0;

void warshall(int A[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                operationCount++;
                A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
            }
        }
    }
}

void displayMatrix(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int A[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    operationCount = 0;
    warshall(A, n);

    printf("\nTransitive Closure Matrix:\n");
    displayMatrix(A, n);
    printf("\nTotal operations performed: %d\n", operationCount);

    return 0;
}
