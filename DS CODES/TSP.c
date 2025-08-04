#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int operationCount = 0; // Global variable to count the number of permutations checked

// Function to calculate total cost of a given permutation
int calculateTotalCost(int *perm, int n, int Cost[n][n]) {
    int totalCost = 0;
    for (int i = 0; i < n - 1; i++) {
        totalCost += Cost[perm[i]][perm[i + 1]];
    }
    totalCost += Cost[perm[n - 1]][perm[0]];
    return totalCost;
}

// Recursive function to generate permutations and count operations
void generatePermutations(int *arr, int l, int r, int n, int Cost[n][n], int *minCost, int *optimalRoute) {
    if (l == r) {
        operationCount++; // Count this permutation as one operation
        int totalCost = calculateTotalCost(arr, n, Cost);
        if (totalCost < *minCost) {
            *minCost = totalCost;
            for (int i = 0; i < n; i++) {
                optimalRoute[i] = arr[i];
            }
        }
    } else {
        for (int i = l; i <= r; i++) {
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;

            generatePermutations(arr, l + 1, r, n, Cost, minCost, optimalRoute);

            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}

// TSP function with permutation generation
void TSP(int n, int Cost[n][n]) {
    int minCost = INT_MAX;
    int optimalRoute[n];
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    generatePermutations(arr, 1, n - 1, n, Cost, &minCost, optimalRoute);

    printf("\nThe minimum cost is: %d\n", minCost);
    printf("The optimal route is: 0 ");
    for (int i = 1; i < n; i++) {
        printf("%d ", optimalRoute[i]);
    }
    printf("0\n");

    printf("Operation count (number of permutations checked): %d\n", operationCount);
}

// Main function with input
int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int Cost[n][n];
    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Cost[i][j]);
        }
    }

    TSP(n, Cost);
    return 0;
}
