#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
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

// Function to display the sparse matrix
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Row: %d, Col: %d, Value: %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    struct Node* sparseMatrix = NULL;

    // Inserting non-zero elements
    insertEnd(&sparseMatrix, 0, 2, 5);
    insertEnd(&sparseMatrix, 1, 4, 3);
    insertEnd(&sparseMatrix, 2, 2, 4);
    insertEnd(&sparseMatrix, 3, 1, 2);
    insertEnd(&sparseMatrix, 3, 3, 8);
    insertEnd(&sparseMatrix, 4, 0, 7);

    printf("Sparse Matrix Representation:\n");
    display(sparseMatrix);

    return 0;
}
