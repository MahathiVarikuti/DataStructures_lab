#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void checkATM(int N, int K) {
    Queue* queue = createQueue(N);
    for (int i = 1; i <= N; i++) {
        enqueue(queue, i);
    }

    int groupSize = 3;
    int found = 0;

    while (!isEmpty(queue)) {
        int group[groupSize];
        for (int i = 0; i < groupSize; i++) {
            group[i] = dequeue(queue);
        }

        for (int i = 0; i < groupSize; i++) {
            if (group[i] == K && group[(i + 1) % groupSize] == K + 1) {
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    if (found) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(queue->array);
    free(queue);
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N, K;
        printf("Enter N and K: ");
        scanf("%d %d", &N, &K);
        checkATM(N, K);
    }

    return 0;
}
