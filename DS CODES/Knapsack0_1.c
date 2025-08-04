#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n, int *operationCount) {
    int K[MAX][MAX];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            (*operationCount)++;
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n, W;
    int wt[MAX], val[MAX], operationCount = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, wt, val, n, &operationCount);

    printf("\nMaximum value in knapsack = %d\n", maxValue);
    printf("Total operations performed: %d\n", operationCount);

    return 0;
}
