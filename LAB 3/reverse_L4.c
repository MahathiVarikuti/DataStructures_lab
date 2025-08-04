#include <stdio.h>
void Reverse(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    int temp;
    while (start < end) {
        // Swap the elements
        temp = *start;
        *start = *end;
        *end = temp;
        // Move the pointers
        start++;
        end--;
    }
}
int main() {
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Reverse(arr, n);
    printf("Reversed array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
