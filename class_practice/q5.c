#include <stdio.h>
#define MAX 100
void insert(int tree[], int element, int index) {
    tree[index] = element;
}
void display(int tree[], int size) {
    for (int i = 0; i < size; i++) {
        if (tree[i] != 0)
            printf("%d ", tree[i]);
    }
    printf("\n");
}
int main() {
    int tree[MAX] = {0};
    insert(tree, 1, 0);
    insert(tree, 2, 1);
    insert(tree, 3, 2);
    insert(tree, 4, 3);
    display(tree, 10);
    return 0;
}
