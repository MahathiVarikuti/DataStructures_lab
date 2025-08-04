//Binary Tree Implementation and Recursive Traversals
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

// Recursive In-order Traversal
void inorderRecursive(Node* root) {
    if (root == NULL)
        return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

// Recursive Pre-order Traversal
void preorderRecursive(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// Recursive Post-order Traversal
void postorderRecursive(Node* root) {
    if (root == NULL)
        return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    int choice, data, numNodes, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        printf("Enter node value: ");
        scanf("%d", &data);
        root = insertIterative(root, data);
    }

    do {
        printf("\nMenu:\n");
        printf("1. In-order Traversal (Recursive)\n");
        printf("2. Pre-order Traversal (Recursive)\n");
        printf("3. Post-order Traversal (Recursive)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("In-order Traversal:\n");
                inorderRecursive(root);
                break;
            case 2:
                printf("Pre-order Traversal:\n");
                preorderRecursive(root);
                break;
            case 3:
                printf("Post-order Traversal:\n");
                postorderRecursive(root);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
