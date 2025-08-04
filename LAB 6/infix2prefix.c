#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 100

typedef struct {
    char items[MAXSTACK];
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

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    } else {
        return s->items[s->top];
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void reverse(char *exp) {
    int i ;
    int length = strlen(exp);
    for (i= 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initializeStack(s);
    int i,k = 0;
    for (i = 0; infix[i]; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[k++] = pop(s);
            }
            pop(s); // Remove '(' from stack
        } else if (isOperator(infix[i])) {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(infix[i])) {
                postfix[k++] = pop(s);
            }
            push(s, infix[i]);
        }
    }
    while (!isEmpty(s)) {
        postfix[k++] = pop(s);
    }
    postfix[k] = '\0';
    free(s);
}

void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);
    int i ;
    for (i= 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    char postfix[MAXSTACK];
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAXSTACK], prefix[MAXSTACK];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
