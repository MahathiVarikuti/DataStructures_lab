//Using pointer to pointer.
#include <stdio.h>
int main() {
    int var = 10;
    int *ptr = &var;      // Pointer to an integer
    int **pptr = &ptr;    // Pointer to pointer
    // Printing the value using pointer to pointer
    printf("Value of var = %d\n", var);
    printf("Value of *ptr = %d\n", *ptr);
    printf("Value of **pptr = %d\n", **pptr);
    return 0;
}
