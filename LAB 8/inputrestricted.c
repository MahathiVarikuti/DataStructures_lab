#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int count;
} Dequeue;

void initDequeue(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->count = 0;
}

int isFull(Dequeue *dq) {
    return dq->count == MAX;
}

int isEmpty(Dequeue *dq) {
    return dq->count == 0;
}

void addLeft(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
    dq->count++;
}

int deleteLeft(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    dq->count--;
    return value;
}

int deleteRight(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    dq->count--;
    return value;
}

void display(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return;
    }
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Dequeue dq;
    initDequeue(&dq);

    addLeft(&dq, 10);
    addLeft(&dq, 20);
    addLeft(&dq, 30);
    display(&dq);

    printf("Deleted from left: %d\n", deleteLeft(&dq));
    display(&dq);

    printf("Deleted from right: %d\n", deleteRight(&dq));
    display(&dq);

    return 0;
}
