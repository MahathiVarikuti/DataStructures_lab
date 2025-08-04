#include <stdio.h>

// Function to find the index of the minimum element
int minIndex(int arr[], int i, int j) {
    if (i == j) {
        return i;
    }
    int k = minIndex(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

// Recursive function to perform selection sort
void recurSelectionSort(int arr[], int n, int index) {
    if (index == n) {
        return;
    }
    // Find the minimum element in the unsorted part
    int k = minIndex(arr, index, n - 1);
    // Swap the found minimum element with the first element
    if (k != index) {
        int temp = arr[k];
        arr[k] = arr[index];
        arr[index] = temp;
    }
    // Recursively call the function for the remaining part
    recurSelectionSort(arr, n, index + 1);
}

int main() {
    int n,i;

    // Taking input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input for the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using recursive selection sort
    recurSelectionSort(arr, n, 0);

    // Displaying the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
