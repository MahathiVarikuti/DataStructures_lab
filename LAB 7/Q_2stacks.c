#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

typedef struct {
    Stack s1, s2;
} Queue;

void enqueue(Queue* q, int value) {
    push(&q->s1, value);
}

int dequeue(Queue* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

void display(Queue* q) {
    int i;
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    for ( i = q->s2.top; i >= 0; i--) {
        printf("%d ", q->s2.items[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1.top = q->s2.top = -1;
    int choice, value;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
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
