#include <stdio.h>

// Function to find and print all triplets with zero sum
void findTriplets(int arr[], int n) {
    int found = 0,i,j,k;
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }
    if (found == 0) {
        printf("No triplets found\n");
    }
}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}
