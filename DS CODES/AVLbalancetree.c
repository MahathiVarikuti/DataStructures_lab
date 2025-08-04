#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key, height;
    struct node *left, *right;
} NODE;

// Utility to get height
int height(NODE *n) {
    return n ? n->height : 0;
}

// Max function
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
NODE* newNode(int key) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
NODE* rightRotate(NODE* y) {
    NODE* x = y->left;
    NODE* T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
NODE* leftRotate(NODE* x) {
    NODE* y = x->right;
    NODE* T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(NODE* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Iterative AVL insert
NODE* insertIterative(NODE* root, int key) {
    // Stack-like array to keep path
    NODE* stack[100];
    int top = -1;

    NODE* curr = root;
    NODE* parent = NULL;

    // Traverse to insertion point
    while (curr != NULL) {
        stack[++top] = curr;
        parent = curr;
        if (key < curr->key)
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else {
            printf("Duplicate key not allowed\n");
            return root;
        }
    }

    NODE* new_node = newNode(key);
    if (parent == NULL)
        return new_node;
    else if (key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;

    // Backtrack and update height + balance
    while (top >= 0) {
        curr = stack[top--];
        curr->height = 1 + max(height(curr->left), height(curr->right));
        int balance = getBalance(curr);

        // Perform rotations if unbalanced
        if (balance > 1 && key < curr->left->key) {
            // Left Left
            if (top == -1) return rightRotate(curr);
            if (stack[top]->left == curr)
                stack[top]->left = rightRotate(curr);
            else
                stack[top]->right = rightRotate(curr);
        } else if (balance < -1 && key > curr->right->key) {
            // Right Right
            if (top == -1) return leftRotate(curr);
            if (stack[top]->left == curr)
                stack[top]->left = leftRotate(curr);
            else
                stack[top]->right = leftRotate(curr);
        } else if (balance > 1 && key > curr->left->key) {
            // Left Right
            curr->left = leftRotate(curr->left);
            if (top == -1) return rightRotate(curr);
            if (stack[top]->left == curr)
                stack[top]->left = rightRotate(curr);
            else
                stack[top]->right = rightRotate(curr);
        } else if (balance < -1 && key < curr->right->key) {
            // Right Left
            curr->right = rightRotate(curr->right);
            if (top == -1) return leftRotate(curr);
            if (stack[top]->left == curr)
                stack[top]->left = leftRotate(curr);
            else
                stack[top]->right = leftRotate(curr);
        }
    }

    return root;
}

// Inorder traversal
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Main
int main() {
    NODE* root = NULL;
    int ch, val;

    while (1) {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insertIterative(root, val);
                break;
            case 2:
                printf("Inorder traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}
