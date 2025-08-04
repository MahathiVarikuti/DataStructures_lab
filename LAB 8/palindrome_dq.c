#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int front, rear;
} Deque;

void insertRear(Deque* dq, char value) {
    if ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = value;
}

char deleteFront(Deque* dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return '\0';
    }
    char value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return value;
}

char deleteRear(Deque* dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return '\0';
    }
    char value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    return value;
}

int isPalindrome(char* str) {
    int i;
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = -1;
    int len = strlen(str);

    for ( i = 0; i < len; i++) {
        insertRear(dq, str[i]);
    }

    while (dq->front != dq->rear && dq->front != (dq->rear + 1) % MAX) {
        if (deleteFront(dq) != deleteRear(dq)) {
            free(dq);
            return 0;
        }
    }
    free(dq);
    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    return 0;
}
