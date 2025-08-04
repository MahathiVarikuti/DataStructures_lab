#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

int comparisons = 0;

// Build shift table
void shiftTable(char pattern[], int m, int shift[]) {
    for (int i = 0; i < MAX; i++)
        shift[i] = m;
    for (int j = 0; j < m - 1; j++)
        shift[(int)pattern[j]] = m - 1 - j;
}

// Horspool search
int horspool(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shift[MAX];
    shiftTable(pattern, m, shift);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            comparisons++;
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            if (k == 0) comparisons++;  // Mismatch at first char
            i += shift[(int)text[i]];
        }
    }
    return -1;
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    comparisons = 0;
    int pos = horspool(text, pattern);

    if (pos != -1) {
        printf("Pattern found at position: %d\n", pos);
        printf("Successful Search - Comparisons: %d\n", comparisons);
    } else {
        printf("Pattern not found\n");
        printf("Unsuccessful Search - Comparisons: %d\n", comparisons);
    }

    return 0;
}
