#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int array[MAX];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->array[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->array[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

void insertAtBottom(Stack *s, int value) {
    if (isEmpty(s)) {
        push(s, value);
    } else {
        int temp = pop(s);
        insertAtBottom(s, value);
        push(s, temp);
    }
}

void reverseStack(Stack *s) {
    if (!isEmpty(s)) {
        int temp = pop(s);
        reverseStack(s);
        insertAtBottom(s, temp);
    }
}

void printStack(Stack *s) {
    if (!isEmpty(s)) {
        int temp = pop(s);
        printStack(s);
        printf("%d ", temp);
        push(s, temp);
    }
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Original Stack: ");
    printStack(&s);
    printf("\n");

    reverseStack(&s);

    printf("Reversed Stack: ");
    printStack(&s);
    printf("\n");

    return 0;
}
