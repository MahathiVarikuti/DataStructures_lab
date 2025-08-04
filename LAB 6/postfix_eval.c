#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

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

void evaluatePostfix(char postfix[]) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initializeStack(s);
    int i = 0;
    char ch;
    int val;
    int A, B;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(s, ch - '0');
        } else {
            A = pop(s);
            B = pop(s);
            switch (ch) {
                case '+':
                    val = B + A;
                    break;
                case '-':
                    val = B - A;
                    break;
                case '*':
                    val = B * A;
                    break;
                case '/':
                    val = B / A;
                    break;
            }
            push(s, val);
        }
    }
    printf("Result of expression evaluation: %d\n", pop(s));
    free(s);
}

int main() {
    char postfix[POSTFIXSIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    evaluatePostfix(postfix);
    return 0;
}
