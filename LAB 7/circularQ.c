#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX][100];
    int front, rear;
} CircularQueue;

void insert(CircularQueue* q, char* value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->items[q->rear], value);
}

void delete(CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %s\n", q->items[q->front]);
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX;
}

void display(CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%s ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%s\n", q->items[i]);
}

int main() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = -1;
    int choice;
    char value[100];

    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                scanf("%s", value);
                insert(q, value);
                break;
            case 2:
                delete(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                free(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
