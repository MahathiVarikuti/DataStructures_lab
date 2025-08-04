//Demonstrate passing pointers to a function.
#include <stdio.h>
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x = 10, y = 20;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    Swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}
