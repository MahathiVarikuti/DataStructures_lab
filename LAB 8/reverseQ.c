#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front++];
}

int empty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void reverseQueue(Queue* q) {
    if (empty(q)) {
        return;
    }
    int data = dequeue(q);
    reverseQueue(q);
    enqueue(q, data);
}

void display(Queue* q) {
    int i;
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for ( i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = q.rear = -1;
    int choice, value;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Reverse Queue\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                reverseQueue(&q);
                printf("Queue reversed\n");
                break;
            case 4:
                display(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
