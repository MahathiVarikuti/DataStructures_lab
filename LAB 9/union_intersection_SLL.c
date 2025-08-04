#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

Node* unionLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp = head1;
    while (temp != NULL) {
        insert(&result, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL) {
        insert(&result, temp->data);
        temp = temp->next;
    }
    return result;
}

Node* intersectionLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp1 = head1;
    while (temp1 != NULL) {
        Node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                insert(&result, temp1->data);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* unionHead = NULL;
    Node* intersectionHead = NULL;

    insert(&head1, 10);
    insert(&head1, 15);
    insert(&head1, 5);

    insert(&head2, 10);
    insert(&head2, 20);
    insert(&head2, 5);

    printf("List 1: ");
    displayList(head1);
    printf("List 2: ");
    displayList(head2);

    unionHead = unionLists(head1, head2);
    printf("Union: ");
    displayList(unionHead);

    intersectionHead = intersectionLists(head1, head2);
    printf("Intersection: ");
    displayList(intersectionHead);

    return 0;
}
