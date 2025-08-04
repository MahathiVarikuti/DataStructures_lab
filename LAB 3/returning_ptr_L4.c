//Demonstrate Returning pointer from a function.
#include <stdio.h>
// Function to find the larger of two numbers and return a pointer to it
int* Larger(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}
int main() {
    int x = 10, y = 20;
    int *larger;
    // Calling the function that returns a pointer
    larger = Larger(&x, &y);
    printf("The larger number is: %d\n", *larger);
    return 0;
}
