//Recursive Functions for Binary Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insertIterative(Node* root, int data) {
    Node* newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
        return root;
    }
    Node* parent = NULL;
    Node* current = root;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

// Recursive function to create a copy of a BT
Node* copyTree(Node* root) {
    if (root == NULL)
        return NULL;
    Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

// Recursive function to test for equality of two BTs
int areEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data &&
            areEqual(root1->left, root2->left) &&
            areEqual(root1->right, root2->right));
}

// Recursive In-order Traversal for displaying
void inorderRecursive(Node* root) {
    if (root == NULL)
        return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    int choice, data, numNodes, i;

    do {
        printf("\nMenu:\n");
        printf("1. Insert nodes into the first tree\n");
        printf("2. Copy first tree to second tree\n");
        printf("3. Check if both trees are equal\n");
        printf("4. Display first tree (In-order Traversal)\n");
        printf("5. Display second tree (In-order Traversal)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &numNodes);
                for (i = 0; i < numNodes; i++) {
                    printf("Enter node value: ");
                    scanf("%d", &data);
                    root1 = insertIterative(root1, data);
                }
                break;
            case 2:
                root2 = copyTree(root1);
                printf("Tree copied successfully.\n");
                break;
            case 3:
                if (areEqual(root1, root2)) {
                    printf("Both trees are equal.\n");
                } else {
                    printf("Trees are not equal.\n");
                }
                break;
            case 4:
                printf("First tree (In-order Traversal):\n");
                inorderRecursive(root1);
                printf("\n");
                break;
            case 5:
                printf("Second tree (In-order Traversal):\n");
                inorderRecursive(root2);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
