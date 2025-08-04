#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode; // Circular linked list
    return newNode;
}

void insertEnd(Node** head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = (*head)->next;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

Node* addPolynomials(Node* head1, Node* head2) {
    Node* result = createNode(0, -1); // Header node
    Node* temp1 = head1->next;
    Node* temp2 = head2->next;

    while (temp1 != head1 && temp2 != head2) {
        if (temp1->exp > temp2->exp) {
            insertEnd(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            insertEnd(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            insertEnd(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != head1) {
        insertEnd(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != head2) {
        insertEnd(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

Node* subtractPolynomials(Node* head1, Node* head2) {
    Node* result = createNode(0, -1); // Header node
    Node* temp1 = head1->next;
    Node* temp2 = head2->next;

    while (temp1 != head1 && temp2 != head2) {
        if (temp1->exp > temp2->exp) {
            insertEnd(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            insertEnd(&result, -temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            insertEnd(&result, temp1->coeff - temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != head1) {
        insertEnd(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != head2) {
        insertEnd(&result, -temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

Node* multiplyPolynomials(Node* head1, Node* head2) {
    Node* result = createNode(0, -1); // Header node
    Node* temp1 = head1->next;
    Node* temp2;

    while (temp1 != head1) {
        temp2 = head2->next;
        while (temp2 != head2) {
            insertEnd(&result, temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

void displayPolynomial(Node* head) {
    Node* temp = head->next;
    while (temp != head) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != head) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Node *head1 = createNode(0, -1), *head2 = createNode(0, -1), *result = NULL;
    int choice, coeff, exp;

    while (1) {
        printf("1. Insert Polynomial 1\n2. Insert Polynomial 2\n3. Add Polynomials\n4. Subtract Polynomials\n5. Multiply Polynomials\n6. Display Polynomial 1\n7. Display Polynomial 2\n8. Display Result\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and exponent: ");
                scanf("%d %d", &coeff, &exp);
                insertEnd(&head1, coeff, exp);
                break;
            case 2:
                printf("Enter coefficient and exponent: ");
                scanf("%d %d", &coeff, &exp);
                insertEnd(&head2, coeff, exp);
                break;
            case 3:
                result = addPolynomials(head1, head2);
                printf("Polynomials added\n");
                break;
            case 4:
                result = subtractPolynomials(head1, head2);
                printf("Polynomials subtracted\n");
                break;
            case 5:
                result = multiplyPolynomials(head1, head2);
                printf("Polynomials multiplied\n");
                break;
            case 6:
                printf("Polynomial 1: ");
                displayPolynomial(head1);
                break;
            case 7:
                printf("Polynomial 2: ");
                displayPolynomial(head2);
                break;
            case 8:
                printf("Result: ");
                displayPolynomial(result);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
