#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to generate permutations of the tasks
void generatePermutations(int *arr, int l, int r, int *minCost, int *Cost, int n) {
    if (l == r) {
        int totalCost = 0;
        // Calculate the total cost for the current permutation
        for (int i = 0; i < n; i++) {
            totalCost += Cost[i * n + arr[i]];  // Accessing cost from flattened 2D matrix
        }
        // Update the minCost if a lower cost is found
        if (totalCost < *minCost) {
            *minCost = totalCost;
        }
    } else {
        for (int i = l; i <= r; i++) {
            // Swap arr[l] and arr[i]
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
            // Recurse to generate the next permutation
            generatePermutations(arr, l + 1, r, minCost, Cost, n);
            // Backtrack: Undo the swap
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}

// Function to solve the Assignment Problem
int AssignmentProblem(int *Cost, int n) {
    int minCost = 999999;  // Initialize a large number for minimum cost
    int arr[n];
    // Initialize arr with task indices [0, 1, 2, ..., n-1]
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    // Generate all permutations of task assignments and calculate the minimum cost
    generatePermutations(arr, 0, n - 1, &minCost, Cost, n);
    return minCost;
}

int main() {
    int n;
    printf("Enter the number of tasks/workers: ");
    scanf("%d", &n);

    int Cost[n][n];  // 2D array for storing cost matrix
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Cost[i][j]);
        }
    }

    int minCost = AssignmentProblem((int *)Cost, n);
    printf("The minimum cost of assignment is: %d\n", minCost);

    return 0;
}
