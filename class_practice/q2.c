#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Iterative In-order Traversal
void iterativeInorder(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;
    while (curr != NULL || top >= 0) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Iterative Pre-order Traversal
void iterativePreorder(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
}

// Level-order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Iterative Inorder: ");
    iterativeInorder(root);
    printf("\nIterative Preorder: ");
    iterativePreorder(root);
    printf("\nLevel Order: ");
    levelOrder(root);
    return 0;
}

