#include <stdio.h>
#include <stdlib.h>

void bishuAndSoldiers(int *powers, int n, int *queries, int q) {
    for (int i = 0; i < q; i++) {
        int m = queries[i];
        int count = 0;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (powers[j] <= m) {
                count++;
                sum += powers[j];
            }
        }
        printf("%d %d\n", count, sum);
    }
}

int main() {
    int n;
    printf("Enter the number of soldiers: ");
    scanf("%d", &n);

    int *powers = (int *)malloc(n * sizeof(int));
    printf("Enter the powers of the soldiers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &powers[i]);
    }

    int q;
    printf("Enter the number of rounds: ");
    scanf("%d", &q);

    int *queries = (int *)malloc(q * sizeof(int));
    printf("Enter the power for each round: ");
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
    }

    bishuAndSoldiers(powers, n, queries, q);

    free(powers);
    free(queries);
    return 0;
}
