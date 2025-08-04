//b. Menu driven program to define a stack of characters
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} STACK;

void push(STACK *s, char item) {
    if (s->top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = item;
    }
}

void pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped item: %c\n", s->arr[s->top]);
        s->top--;
    }
}

void display(STACK *s) {
    int i;
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for ( i = 0; i <= s->top; i++) {
            printf("%c ", s->arr[i]);
        }
        printf("\n");
    }
}

int isEmpty(STACK *s) {
    return s->top == -1;
}

int isFull(STACK *s) {
    return s->top == (MAX - 1);
}

int main() {
    STACK s;
    s.top = -1;
    int choice;
    char item;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the character to push: ");
                scanf(" %c", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
