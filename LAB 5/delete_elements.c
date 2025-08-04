//e. Delete k elements which are smaller than the next element
#include <stdio.h>
#include <stdlib.h>

void deleteElements(int arr[], int *n, int k) {
    int i,j,count = 0;
    for ( i = 0; i < *n - 1 && count < k; i++) {
        if (arr[i] < arr[i + 1]) {
            for ( j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            i = -1;
            count++;
        }
    }
}

int main() {
    int n,i, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);

    deleteElements(arr, &n, k);

    printf("Array after deleting %d elements: ", k);
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
