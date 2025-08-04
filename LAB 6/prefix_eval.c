#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 100

typedef struct {
    int items[MAXSTACK];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top >= MAXSTACK - 1;
}

int isEmpty(Stack *s) {
    return s->top < 0;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = item;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

int evaluatePrefix(char* expr) {
    int i ;
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initializeStack(s);
    int length = strlen(expr);
    for (i = length - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            push(s, expr[i] - '0');
        } else {
            int A = pop(s);
            int B = pop(s);
            switch (expr[i]) {
                case '+':
                    push(s, A + B);
                    break;
                case '-':
                    push(s, A - B);
                    break;
                case '*':
                    push(s, A * B);
                    break;
                case '/':
                    push(s, A / B);
                    break;
            }
        }
    }
    int result = pop(s);
    free(s);
    return result;
}

int main() {
    char expr[MAXSTACK];
    printf("Enter a prefix expression: ");
    scanf("%s", expr);
    int result = evaluatePrefix(expr);
    printf("Result of expression evaluation: %d\n", result);
    return 0;
}
