#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

Node* addNumbers(Node* head1, Node* head2) {
    Node* result = NULL;
    Node *temp1 = head1->prev, *temp2 = head2->prev;
    int carry = 0;

    while (temp1 != head1 || temp2 != head2 || carry) {
        int sum = carry;
        if (temp1 != head1) {
            sum += temp1->data;
            temp1 = temp1->prev;
        }
        if (temp2 != head2) {
            sum += temp2->data;
            temp2 = temp2->prev;
        }
        carry = sum / 10;
        insertEnd(&result, sum % 10);
    }
    return result;
}

void displayList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node *head1 = NULL, *head2 = NULL, *result = NULL;
    char num1[100], num2[100];

    printf("Enter first number: ");
    scanf("%s", num1);
    printf("Enter second number: ");
    scanf("%s", num2);

    for (int i = strlen(num1) - 1; i >= 0; i--) {
        insertEnd(&head1, num1[i] - '0');
    }
    for (int i = strlen(num2) - 1; i >= 0; i--) {
        insertEnd(&head2, num2[i] - '0');
    }

    result = addNumbers(head1, head2);
    printf("Sum: ");
    displayList(result);

    return 0;
}
