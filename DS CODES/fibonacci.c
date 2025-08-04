#include <stdio.h>

int opcount = 0; // Global variable to count function calls

int recursiveFibonacci(int n) {
    opcount++; // Each function call is an operation
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main() {
    int n, result;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    result = recursiveFibonacci(n);

    printf("Fibonacci number F(%d) = %d\n", n, result);
    printf("Operation Count: %d\n", opcount);

    return 0;
}
