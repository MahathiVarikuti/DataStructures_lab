#include <stdio.h>
#include <string.h>

int stringmatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j, opcount = 0;

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            opcount++;
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            printf("Operation count: %d\n", opcount);
            return i;
        }
        if (j < m) {
            opcount++; // count the mismatch comparison
        }
    }

    printf("Pattern not found\n");
    printf("Operation count: %d\n", opcount);
    return -1;
}

int main() {
    char text[1000], pattern[1000];
    printf("Enter the text: ");
    scanf(" %[^\n]", text);
    printf("Enter the pattern to search: ");
    scanf(" %[^\n]", pattern);

    stringmatch(text, pattern);
    return 0;
}
