#include <stdio.h>

int opcount = 0; // Count comparisons

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        opcount++; // Each comparison counted
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

int main() {
    int A[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    quickSort(A, 0, n - 1);

    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nOperation Count = %d\n", opcount);
    return 0;
}
