#include <stdio.h>

int opcount = 0; // To count comparisons

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        opcount++; // Count each comparison
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int A[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    mergeSort(A, 0, n - 1);

    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nOperation Count = %d\n", opcount);
    return 0;
}
