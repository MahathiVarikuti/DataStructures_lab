#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char s[]) {
    int length = strlen(s);
    int mid = length / 2;
    int i;
    char stack[mid];

    for (i = 0; i < mid; i++) {
        stack[i] = s[i];
    }

    if (length % 2 != 0) {
        i++;
    }

    while (s[i] != '\0') {
        char ele = stack[--i];
        if (ele != s[i]) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    char s[] = "YAY";
    if (isPalindrome(s)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
