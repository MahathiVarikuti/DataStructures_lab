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

// Recursive Copy of Binary Tree
struct Node* copyTree(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

// Test if Two Trees are Equal
int isEqual(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->data == root2->data) && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
}

int main() {
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct Node* root2 = copyTree(root1);
    printf("Trees are %s\n", isEqual(root1, root2) ? "equal" : "not equal");
    return 0;
}
