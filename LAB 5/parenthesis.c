//a. Check if the given parenthesized expression has properly matching open and closing parenthesis
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void push(struct Stack *s, char item) {
    if (s->top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = item;
    }
}

void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
    } else {
        s->top--;
    }
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    else if (char1 == '{' && char2 == '}') return 1;
    else if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int areParenthesesBalanced(char exp[]) {
    int i;
    struct Stack s;
    s.top = -1;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.top == -1 || !isMatchingPair(s.arr[s.top], exp[i])) {
                return 0;
            } else {
                pop(&s);
            }
        }
    }
    return s.top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (areParenthesesBalanced(exp)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
