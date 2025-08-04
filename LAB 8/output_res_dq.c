#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX][100];
    int front, rear;
} Deque;

void insertFront(Deque* dq, char* value) {
    if ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    strcpy(dq->items[dq->front], value);
}

void insertRear(Deque* dq, char* value) {
    if ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    strcpy(dq->items[dq->rear], value);
}

void deleteFront(Deque* dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted: %s\n", dq->items[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void display(Deque* dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    while (i != dq->rear) {
        printf("%s ", dq->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%s\n", dq->items[i]);
}

int main() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = -1;
    int choice;
    char value[100];

    while (1) {
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter string to insert at front: ");
                scanf("%s", value);
                insertFront(dq, value);
                break;
            case 2:
                printf("Enter string to insert at rear: ");
                scanf("%s", value);
                insertRear(dq, value);
                break;
            case 3:
                deleteFront(dq);
                break;
            case 4:
                display(dq);
                break;
            case 5:
                free(dq);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
