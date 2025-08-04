#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

char *buffer[MAX_LINES];
int line_count = 0;

void insertLine(char *line) {
    if (line_count < MAX_LINES) {
        buffer[line_count] = (char *)malloc((strlen(line) + 1) * sizeof(char));
        strcpy(buffer[line_count], line);
        line_count++;
    } else {
        printf("Buffer is full.\n");
    }
}

void deleteLine(int line_number) {
    if (line_number < 1 || line_number > line_count) {
        printf("Invalid line number.\n");
        return;
    }
    free(buffer[line_number - 1]);
    for (int i = line_number - 1; i < line_count - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    line_count--;
}

void searchWord(char *word) {
    for (int i = 0; i < line_count; i++) {
        if (strstr(buffer[i], word) != NULL) {
            printf("Word found in line %d: %s\n", i + 1, buffer[i]);
        }
    }
}

void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", buffer[i]);
    }
    fclose(file);
    printf("Buffer saved to %s\n", filename);
}

void displayBuffer() {
    printf("Buffer content:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, buffer[i]);
    }
}

int main() {
    char command[10];
    char line[MAX_LENGTH];
    char word[MAX_LENGTH];
    int line_number;

    while (1) {
        printf("Enter command (insert, delete, search, save, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            printf("Enter line to insert: ");
            getchar(); // to consume the newline character left by scanf
            fgets(line, MAX_LENGTH, stdin);
            line[strcspn(line, "\n")] = '\0'; // remove newline character
            insertLine(line);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter line number to delete: ");
            scanf("%d", &line_number);
            deleteLine(line_number);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter word to search: ");
            scanf("%s", word);
            searchWord(word);
        } else if (strcmp(command, "save") == 0) {
            saveToFile("output.txt");
        } else if (strcmp(command, "display") == 0) {
            displayBuffer();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    for (int i = 0; i < line_count; i++) {
        free(buffer[i]);
    }

    return 0;
}
