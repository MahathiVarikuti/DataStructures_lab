#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 100

typedef struct {
    char items[MAXSTACK][MAXSTACK];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top >= MAXSTACK - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        strcpy(s->items[++(s->top)], item);
    }
}

char* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        return s->items[(s->top)--];
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void prefixToPostfix(char *prefix, char *postfix) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initializeStack(s);
    int length = strlen(prefix);
int i;
    for (i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            char *op1 = pop(s);
            char *op2 = pop(s);
            char temp[MAXSTACK];
            snprintf(temp, sizeof(temp), "%s%s%c", op1, op2, prefix[i]);
            push(s, temp);
        } else {
            char operand[2] = {prefix[i], '\0'};
            push(s, operand);
        }
    }

    strcpy(postfix, pop(s));
    free(s);
}

int main() {
    char prefix[MAXSTACK], postfix[MAXSTACK];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    prefixToPostfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
