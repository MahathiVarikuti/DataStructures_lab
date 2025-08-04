#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX / 2];
    int front, rear;
} CircularQueue;

void insert(CircularQueue* q, int value) {
    if ((q->rear + 1) % (MAX / 2) == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % (MAX / 2);
    q->items[q->rear] = value;
}

void delete(CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", q->items[q->front]);
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % (MAX / 2);
}

void display(CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % (MAX / 2);
    }
    printf("%d\n", q->items[i]);
}

int main() {
    CircularQueue* q1 = (CircularQueue*)malloc(sizeof(CircularQueue));
    CircularQueue* q2 = (CircularQueue*)malloc(sizeof(CircularQueue));
    q1->front = q1->rear = -1;
    q2->front = q2->rear = -1;
    int choice, value, queueNumber;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (1 or 2): ");
                scanf("%d", &queueNumber);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (queueNumber == 1) insert(q1, value);
                else if (queueNumber == 2) insert(q2, value);
                else printf("Invalid queue number\n");
                break;
            case 2:
                printf("Enter queue number (1 or 2): ");
                scanf("%d", &queueNumber);
                if (queueNumber == 1) delete(q1);
                else if (queueNumber == 2) delete(q2);
                else printf("Invalid queue number\n");
                break;
            case 3:
                printf("Enter queue number (1 or 2): ");
                scanf("%d", &queueNumber);
                if (queueNumber == 1) display(q1);
                else if (queueNumber == 2) display(q2);
                else printf("Invalid queue number\n");
                break;
            case 4:
                free(q1);
                free(q2);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
