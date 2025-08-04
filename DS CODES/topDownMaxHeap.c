#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void insert(int value) {
    heap[size] = value;
    heapifyUp(size);
    size++;
}

void buildHeap(int arr[], int n) {
    size = 0;
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
}

void printHeap() {
    printf("Heap array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int n, arr[MAX];
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    buildHeap(arr, n);
    end = clock();

    printHeap();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
