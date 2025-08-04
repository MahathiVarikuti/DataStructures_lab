#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the union of two lists
struct Node* unionLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;
    while (temp != NULL) {
        insertEnd(&result, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL) {
        struct Node* search = head1;
        int found = 0;
        while (search != NULL) {
            if (search->data == temp->data) {
                found = 1;
                break;
            }
            search = search->next;
        }
        if (!found) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Function to find the intersection of two lists
struct Node* intersectionLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;
    while (temp != NULL) {
        struct Node* search = head2;
        while (search != NULL) {
            if (search->data == temp->data) {
                insertEnd(&result, temp->data);
                break;
            }
            search = search->next;
        }
        temp = temp->next;
    }
    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Creating first list: 1 -> 2 -> 3 -> 4
    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);
    insertEnd(&list1, 4);

    // Creating second list: 3 -> 4 -> 5 -> 6
    insertEnd(&list2, 3);
    insertEnd(&list2, 4);
    insertEnd(&list2, 5);
    insertEnd(&list2, 6);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* unionList = unionLists(list1, list2);
    printf("Union: ");
    display(unionList);

    struct Node* intersectionList = intersectionLists(list1, list2);
    printf("Intersection: ");
    display(intersectionList);

    return 0;
}
