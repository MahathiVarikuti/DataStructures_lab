#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int items[MAXSIZE];
    int top1;
    int top2;
} TwoStacks;

void initializeStacks(TwoStacks *s) {
    s->top1 = -1;
    s->top2 = MAXSIZE;
}

int isFull1(TwoStacks *s) {
    return s->top1 + 1 == s->top2;
}

int isFull2(TwoStacks *s) {
    return s->top2 - 1 == s->top1;
}

int isEmpty1(TwoStacks *s) {
    return s->top1 == -1;
}

int isEmpty2(TwoStacks *s) {
    return s->top2 == MAXSIZE;
}

void push1(TwoStacks *s, int item) {
    if (isFull1(s)) {
        printf("Stack 1 Overflow\n");
    } else {
        s->items[++(s->top1)] = item;
    }
}

void push2(TwoStacks *s, int item) {
    if (isFull2(s)) {
        printf("Stack 2 Overflow\n");
    } else {
        s->items[--(s->top2)] = item;
    }
}

int pop1(TwoStacks *s) {
    if (isEmpty1(s)) {
        printf("Stack 1 Underflow\n");
        return -1;
    } else {
        return s->items[(s->top1)--];
    }
}

int pop2(TwoStacks *s) {
    if (isEmpty2(s)) {
        printf("Stack 2 Underflow\n");
        return -1;
    } else {
        return s->items[(s->top2)++];
    }
}

int main() {
    TwoStacks *s = (TwoStacks *)malloc(sizeof(TwoStacks));
    initializeStacks(s);

    int choice, stackNumber, value;

    while (1) {
        printf("\n1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(s, value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(s, value);
                break;
            case 3:
                value = pop1(s);
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2(s);
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                free(s);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
