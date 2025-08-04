#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly circular linked list
struct Node {
    int coeff;
    int power;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

// Function to display the polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%dx^%d", temp->coeff, temp->power);
        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    } while (temp != head);
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    do {
        if (p1->power > p2->power) {
            insertEnd(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            insertEnd(&result, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            insertEnd(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    } while (p1 != poly1 && p2 != poly2);

    while (p1 != poly1) {
        insertEnd(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != poly2) {
        insertEnd(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Creating first polynomial: 3x^3 + 2x^2 + 1
    insertEnd(&poly1, 3, 3);
    insertEnd(&poly1, 2, 2);
    insertEnd(&poly1, 1, 0);

    // Creating second polynomial: 4x^3 + 3x + 2
    insertEnd(&poly2, 4, 3);
    insertEnd(&poly2, 3, 1);
    insertEnd(&poly2, 2, 0);

    printf("First Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    struct Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
