#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list of size n
struct Node* createCircularList(int n) {
    struct Node* head = createNode(1);
    struct Node* prev = head;
    for (int i = 2; i <= n; i++) {
        struct Node* newNode = createNode(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // Make the list circular
    return head;
}

// Function to solve the Josephus problem
int josephus(int n, int m) {
    struct Node* head = createCircularList(n);
    struct Node* ptr1 = head;
    struct Node* ptr2 = head;

    while (ptr1->next != ptr1) {
        // Find the m-th node
        for (int count = 1; count < m; count++) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        // Remove the m-th node
        ptr2->next = ptr1->next;
        printf("%d has been killed.\n", ptr1->data);
        free(ptr1);
        ptr1 = ptr2->next;
    }

    int survivor = ptr1->data;
    free(ptr1);
    return survivor;
}

int main() {
    int n, m;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the step count (m): ");
    scanf("%d", &m);

    int survivor = josephus(n, m);
    printf("The person to survive is: %d\n", survivor);

    return 0;
}
