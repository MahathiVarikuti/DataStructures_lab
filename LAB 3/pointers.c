#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array and return a pointer to it
int* findMax(int *arr, int size) {
    int *max = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }
    return max;
}

// Function to demonstrate the use of a pointer to a pointer
void pointerToPointer(int **dptr) {
    printf("Value using double pointer: %d\n", **dptr);
}

int main() {
    // Demonstrate passing pointers to a function
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    // Demonstrate returning a pointer from a function
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *max = findMax(arr, size);
    printf("Maximum element: %d\n", *max);

    // Demonstrate using a pointer to a pointer
    int var = 30;
    int *ptr = &var;
    int **dptr = &ptr;
    pointerToPointer(dptr);

    return 0;
}
