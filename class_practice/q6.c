#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Construct Tree for Prefix Expression
struct Node* constructTree(char prefix[], int* index) {
    if (prefix[*index] == '\0') return NULL;
    struct Node* node = createNode(prefix[*index]);
    if (!isdigit(prefix[*index])) {
        (*index)++;
        node->left = constructTree(prefix, index);
        (*index)++;
        node->right = constructTree(prefix, index);
    }
    return node;
}
// Evaluate the Expression Tree
int evaluate(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data - '0';
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);
    if (root->data == '+') return leftEval + rightEval;
    if (root->data == '-') return leftEval - rightEval;
    if (root->data == '*') return leftEval * rightEval;
    if (root->data == '/') return leftEval / rightEval;
    return 0;
}
int main() {
    char prefix[] = "*+53-82";  // Example: prefix expression for (5 + 3) * (8 - 2)
    int index = 0;
    struct Node* root = constructTree(prefix, &index);
    printf("Evaluation Result: %d\n", evaluate(root));
    return 0;
}
