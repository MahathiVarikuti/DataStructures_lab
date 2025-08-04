#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

void insert(PriorityQueue* pq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pq->front == NULL || pq->front->data > value) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node* temp = pq->front;
        while (temp->next != NULL && temp->next->data <= value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int deleteMin(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    Node* temp = pq->front;
    int minValue = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return minValue;
}

void display(PriorityQueue* pq) {
    Node* temp = pq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->front = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert\n2. Delete Min\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(pq, value);
                break;
            case 2:
                value = deleteMin(pq);
                if (value != -1) {
                    printf("Deleted min: %d\n", value);
                }
                break;
            case 3:
                display(pq);
                break;
            case 4:
                free(pq);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
