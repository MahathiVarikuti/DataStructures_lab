//d. Determine whether a given string is palindrome or not using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->arr[s->top--];
    }
}

int isPalindrome(char str[]) {
    int i;
    int len = strlen(str);
    STACK s;
    s.top = -1;
    for ( i = 0; i < len / 2; i++) {
        push(&s, str[i]);
    }
    for ( i = (len + 1) / 2; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}
