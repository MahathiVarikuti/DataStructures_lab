#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    int *array;
    Queue *queues;
    int n;
    int m;
} MultiQueue;

MultiQueue* createMultiQueue(int n, int m) {
    MultiQueue *mq = (MultiQueue *)malloc(sizeof(MultiQueue));
    mq->array = (int *)malloc(m * sizeof(int));
    mq->queues = (Queue *)malloc(n * sizeof(Queue));
    mq->n = n;
    mq->m = m;

    for (int i = 0; i < n; i++) {
        mq->queues[i].front = -1;
        mq->queues[i].rear = -1;
        mq->queues[i].size = 0;
    }

    return mq;
}

int isFull(MultiQueue *mq, int i) {
    return mq->queues[i].size == mq->m / mq->n;
}

int isEmpty(MultiQueue *mq, int i) {
    return mq->queues[i].size == 0;
}

void addQ(MultiQueue *mq, int i, int value) {
    if (isFull(mq, i)) {
        printf("Queue %d is full\n", i);
        return;
    }

    if (mq->queues[i].front == -1) {
        mq->queues[i].front = 0;
    }

    mq->queues[i].rear = (mq->queues[i].rear + 1) % (mq->m / mq->n);
    mq->array[i * (mq->m / mq->n) + mq->queues[i].rear] = value;
    mq->queues[i].size++;
}

int deleteQ(MultiQueue *mq, int i) {
    if (isEmpty(mq, i)) {
        printf("Queue %d is empty\n", i);
        return -1;
    }

    int value = mq->array[i * (mq->m / mq->n) + mq->queues[i].front];
    mq->queues[i].front = (mq->queues[i].front + 1) % (mq->m / mq->n);
    mq->queues[i].size--;

    if (mq->queues[i].size == 0) {
        mq->queues[i].front = -1;
        mq->queues[i].rear = -1;
    }

    return value;
}

void menu() {
    int n, m, choice, i, value;
    printf("Enter the number of queues: ");
    scanf("%d", &n);
    printf("Enter the size of the array: ");
    scanf("%d", &m);

    MultiQueue *mq = createMultiQueue(n, m);

    while (1) {
        printf("\n1. Add to Queue\n2. Delete from Queue\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number and value: ");
                scanf("%d %d", &i, &value);
                addQ(mq, i, value);
                break;
            case 2:
                printf("Enter queue number: ");
                scanf("%d", &i);
                value = deleteQ(mq, i);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                free(mq->array);
                free(mq->queues);
                free(mq);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
