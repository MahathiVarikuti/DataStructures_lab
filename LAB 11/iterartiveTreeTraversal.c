//Iterative Tree Traversals
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    Node* data[MAX];
    int top;
} Stack;

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

void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, Node* node) {
    if (stack->top < MAX - 1) {
        stack->data[++stack->top] = node;
    }
}

Node* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return NULL;
}

void preorderIterative(Node* root) {
    Stack stack;
    initStack(&stack);
    push(&stack, root);
    while (stack.top != -1) {
        Node* node = pop(&stack);
        printf("%d ", node->data);
        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
}

void postorderIterative(Node* root) {
    Stack stack;
    initStack(&stack);
    do {
        while (root) {
            if (root->right)
                push(&stack, root->right);
            push(&stack, root);
            root = root->left;
        }
        root = pop(&stack);
        if (root->right && stack.top != -1 && root->right == stack.data[stack.top]) {
            pop(&stack);
            push(&stack, root);
            root = root->right;
        } else {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (stack.top != -1);
}

void inorderIterative(Node* root) {
    Stack stack;
    initStack(&stack);
    while (1) {
        while (root) {
            push(&stack, root);
            root = root->left;
        }
        if (stack.top == -1)
            break;
        root = pop(&stack);
        printf("%d ", root->data);
        root = root->right;
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Node* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
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
        printf("1. Pre-order Traversal (Iterative)\n");
        printf("2. Post-order Traversal (Single Stack)\n");
        printf("3. In-order Traversal (Iterative)\n");
        printf("4. Level-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Pre-order Traversal:\n");
                preorderIterative(root);
                break;
            case 2:
                printf("Post-order Traversal:\n");
                postorderIterative(root);
                break;
            case 3:
                printf("In-order Traversal:\n");
                inorderIterative(root);
                break;
            case 4:
                printf("Level-order Traversal:\n");
                levelOrder(root);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
