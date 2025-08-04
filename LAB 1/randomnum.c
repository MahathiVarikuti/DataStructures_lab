#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 201 // Range from -100 to 100

void generateRandomNumbers(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % RANGE) - 100;
    }
}

void findFrequency(int *arr, int size, int *frequency) {
    for (int i = 0; i < size; i++) {
        frequency[arr[i] + 100]++;
    }
}

void printFrequency(int *frequency) {
    for (int i = 0; i < RANGE; i++) {
        if (frequency[i] > 0) {
            printf("Number %d: %d times\n", i - 100, frequency[i]);
        }
    }
}

int main() {
    srand(time(0));

    int size;
    printf("Enter the number of samples: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    int frequency[RANGE] = {0};

    generateRandomNumbers(arr, size);
    findFrequency(arr, size, frequency);
    printFrequency(frequency);

    free(arr);
    return 0;
}
