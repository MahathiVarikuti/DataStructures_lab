//Expression Tree for Postfix Expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

typedef struct Stack {
    TreeNode* data[100];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, TreeNode* node) {
    if (stack->top < 99) {
        stack->data[++stack->top] = node;
    }
}

TreeNode* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return NULL;
}

TreeNode* constructTree(char postfix[]) {
    Stack stack;
    initStack(&stack);
    int i;
    for ( i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, newNode(postfix[i]));
        } else {
            TreeNode* node = newNode(postfix[i]);
            node->right = pop(&stack);
            node->left = pop(&stack);
            push(&stack, node);
        }
    }
    return pop(&stack);
}

int evaluate(TreeNode* root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data - '0';
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);
    if (root->data == '+') return leftEval + rightEval;
    if (root->data == '-') return leftEval - rightEval;
    if (root->data == '*') return leftEval * rightEval;
    if (root->data == '/') return leftEval / rightEval;
    return 0;
}

void inorder(TreeNode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main() {
    char postfix[100];
    TreeNode* root = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter Postfix Expression\n");
        printf("2. Evaluate Expression Tree\n");
        printf("3. In-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                root = constructTree(postfix);
                break;
            case 2:
                if (root == NULL) {
                    printf("Expression tree not created. Please enter a postfix expression first.\n");
                } else {
                    printf("Expression Tree Evaluation: %d\n", evaluate(root));
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Expression tree not created. Please enter a postfix expression first.\n");
                } else {
                    printf("In-order Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Expression tree not created. Please enter a postfix expression first.\n");
                } else {
                    printf("Pre-order Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("Expression tree not created. Please enter a postfix expression first.\n");
                } else {
                    printf("Post-order Traversal: ");
                    postorder(root);
                    printf("\n");
                }
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
