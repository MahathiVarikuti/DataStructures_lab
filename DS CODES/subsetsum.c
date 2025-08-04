#include <stdio.h>

int count = 0;  // To keep track of the number of recursive calls

// Function to solve the subset-sum problem using backtracking
int subsetSum(int arr[], int n, int sum, int currentSum, int index) {
    count++;  // Incrementing operation count for each function call

    // If the current sum is equal to the required sum
    if (currentSum == sum) {
        return 1;  // Found a subset
    }

    // If all elements are processed or currentSum exceeds the target sum
    if (index >= n || currentSum > sum) {
        return 0;  // No valid subset found
    }

    // Include the current element
    if (subsetSum(arr, n, sum, currentSum + arr[index], index + 1)) {
        return 1;
    }

    // Exclude the current element
    if (subsetSum(arr, n, sum, currentSum, index + 1)) {
        return 1;
    }

    return 0;  // No valid subset found after both possibilities
}

int main() {
    int arr[] = {1, 2, 5, 6, 8};  // The given set
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;  // The desired sum

    if (subsetSum(arr, n, sum, 0, 0)) {
        printf("A subset with the sum %d exists.\n", sum);
    } else {
        printf("No subset with the sum %d exists.\n", sum);
    }

    // Output the operation count (recursive calls)
    printf("Number of operations: %d\n", count);

    return 0;
}
