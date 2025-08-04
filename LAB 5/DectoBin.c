//c. decimal to binary using stack
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} STACK;

void push(STACK *s, int item) {
    if (s->top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = item;
    }
}

int pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}

void decimalToBinary(int num) {
    STACK s;
    s.top = -1;
    while (num > 0) {
        push(&s, num % 2);
        num /= 2;
    }
    printf("Binary equivalent: ");
    while (s.top != -1) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decimalToBinary(num);
    return 0;
}
