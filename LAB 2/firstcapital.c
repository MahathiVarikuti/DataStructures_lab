#include <stdio.h>
#include <ctype.h>

char findFirstCapital(char *str, int index) {
    if (str[index] == '\0') {
        return '\0';
    }
    if (isupper(str[index])) {
        return str[index];
    }
    return findFirstCapital(str, index + 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    char result = findFirstCapital(str, 0);
    if (result != '\0') {
        printf("First capital letter: %c\n", result);
    } else {
        printf("No capital letter found.\n");
    }
    return 0;
}
