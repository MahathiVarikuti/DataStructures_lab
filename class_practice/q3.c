#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
struct Node* constructTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else {
            struct Node* op = createNode(postfix[i]);
            op->right = stack[top--];
            op->left = stack[top--];
            stack[++top] = op;
        }
    }
    return stack[top];
}
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
    char postfix[] = "53+82-*";
    struct Node* root = constructTree(postfix);
    printf("Evaluation Result: %d", evaluate(root));
    return 0;
}
