#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the singly linked list
struct Node {
    char data[100];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void push(struct Node** headRef, char* data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Recursive function to reverse the linked list
void reverseList(struct Node** headRef) {
    struct Node* first;
    struct Node* rest;

    if (*headRef == NULL) {
        return;
    }

    first = *headRef;
    rest = first->next;

    if (rest == NULL) {
        return;
    }

    reverseList(&rest);
    first->next->next = first;
    first->next = NULL;

    *headRef = rest;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, "world");
    push(&head, "hello");

    printf("Original List: ");
    printList(head);

    reverseList(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
