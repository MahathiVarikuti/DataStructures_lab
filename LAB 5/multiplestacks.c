#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int *array;
    int *top;
    int *next;
    int free;
    int n, k;
} KStacks;

KStacks* createKStacks(int k, int n) {
    KStacks *ks = (KStacks *)malloc(sizeof(KStacks));
    ks->n = n;
    ks->k = k;
    ks->array = (int *)malloc(n * sizeof(int));
    ks->top = (int *)malloc(k * sizeof(int));
    ks->next = (int *)malloc(n * sizeof(int));
    ks->free = 0;

    for (int i = 0; i < k; i++) {
        ks->top[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        ks->next[i] = i + 1;
    }
    ks->next[n - 1] = -1;

    return ks;
}

void push(KStacks *ks, int stackNum, int value) {
    if (ks->free == -1) {
        printf("Stack Overflow\n");
        return;
    }

    int i = ks->free;
    ks->free = ks->next[i];
    ks->array[i] = value;
    ks->next[i] = ks->top[stackNum];
    ks->top[stackNum] = i;
}

int pop(KStacks *ks, int stackNum) {
    if (ks->top[stackNum] == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    int i = ks->top[stackNum];
    ks->top[stackNum] = ks->next[i];
    ks->next[i] = ks->free;
    ks->free = i;

    return ks->array[i];
}

int main() {
    int k = 3, n = 10;
    KStacks *ks = createKStacks(k, n);

    push(ks, 0, 15);
    push(ks, 1, 45);
    push(ks, 2, 17);
    push(ks, 0, 49);
    push(ks, 1, 39);
    push(ks, 2, 11);

    printf("Popped from stack 0: %d\n", pop(ks, 0));
    printf("Popped from stack 1: %d\n", pop(ks, 1));
    printf("Popped from stack 2: %d\n", pop(ks, 2));

    free(ks->array);
    free(ks->top);
    free(ks->next);
    free(ks);

    return 0;
}
