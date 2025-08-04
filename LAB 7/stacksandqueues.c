#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int size;
} Stack;

typedef struct {
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    int *array;
    Stack *stacks;
    Queue *queues;
    int n1;
    int n2;
    int m;
} MultiData;

MultiData* createMultiData(int n1, int n2, int m) {
    MultiData *md = (MultiData *)malloc(sizeof(MultiData));
    md->array = (int *)malloc(m * sizeof(int));
    md->stacks = (Stack *)malloc(n1 * sizeof(Stack));
    md->queues = (Queue *)malloc(n2 * sizeof(Queue));
    md->n1 = n1;
    md->n2 = n2;
    md->m = m;

    for (int i = 0; i < n1; i++) {
        md->stacks[i].top = -1;
        md->stacks[i].size = 0;
    }

    for (int i = 0; i < n2; i++) {
        md->queues[i].front = -1;
        md->queues[i].rear = -1;
        md->queues[i].size = 0;
    }

    return md;
}

int isSpaceFull(MultiData *md) {
    int usedSpace = 0;
    for (int i = 0; i < md->n1; i++) {
        usedSpace += md->stacks[i].size;
    }
    for (int i = 0; i < md->n2; i++) {
        usedSpace += md->queues[i].size;
    }
    return usedSpace == md->m;
}

void addStack(MultiData *md, int i, int value) {
    if (isSpaceFull(md)) {
        printf("No space available\n");
        return;
    }

    md->stacks[i].top++;
    md->array[i * (md->m / md->n1) + md->stacks[i].top] = value;
    md->stacks[i].size++;
}

int deleteStack(MultiData *md, int i) {
    if (md->stacks[i].top == -1) {
        printf("Stack %d is empty\n", i);
        return -1;
    }

    int value = md->array[i * (md->m / md->n1) + md->stacks[i].top];
    md->stacks[i].top--;
    md->stacks[i].size--;

    return value;
}

void addQueue(MultiData *md, int i, int value) {
    if (isSpaceFull(md)) {
        printf("No space available\n");
        return;
    }

    if (md->queues[i].front == -1) {
        md->queues[i].front = 0;
    }

    md->queues[i].rear = (md->queues[i].rear + 1) % (md->m / md->n2);
    md->array[md->n1 * (md->m / md->n1) + i * (md->m / md->n2) + md->queues[i].rear] = value;
    md->queues[i].size++;
}

int deleteQueue(MultiData *md, int i) {
    if (md->queues[i].front == -1) {
        printf("Queue %d is empty\n", i);
        return -1;
    }

    int value = md->array[md->n1 * (md->m / md->n1) + i * (md->m / md->n2) + md->queues[i].front];
    md->queues[i].front = (md->queues[i].front + 1) % (md->m / md->n2);
    md->queues[i].size--;

    if (md->queues[i].size == 0) {
        md->queues[i].front = -1;
        md->queues[i].rear = -1;
    }

    return value;
}

void menu() {
    int n1, n2, m, choice, i, value;
    printf("Enter the number of stacks: ");
    scanf("%d", &n1);
    printf("Enter the number of queues: ");
    scanf("%d", &n2);
    printf("Enter the size of the array: ");
    scanf("%d", &m);

    MultiData *md = createMultiData(n1, n2, m);

    while (1) {
        printf("\n1. Add to Stack\n2. Delete from Stack\n3. Add to Queue\n4. Delete from Queue\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number and value: ");
                scanf("%d %d", &i, &value);
                addStack(md, i, value);
                break;
            case 2:
                printf("Enter stack number: ");
                scanf("%d", &i);
                value = deleteStack(md, i);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                printf("Enter queue number and value: ");
                scanf("%d %d", &i, &value);
                addQueue(md, i, value);
                break;
            case 4:
                printf("Enter queue number: ");
                scanf("%d", &i);
                value = deleteQueue(md, i);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 5:
                free(md->array);
                free(md->stacks);
                free(md->queues);
                free(md);
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
