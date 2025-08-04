#include <stdio.h>
#include <stdlib.h>
int Smallest(int *arr, int n) {
    int smallest = *arr;
    int i;
    for (i = 1; i < n; i++) {
        if (*(arr + i) < smallest) {
            smallest = *(arr + i);
        }
    }
    return smallest;
}
int main() {
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int smallest = Smallest(arr, n);
    printf("The smallest element in the array is: %d\n", smallest);
    free(arr);
    return 0;
}
