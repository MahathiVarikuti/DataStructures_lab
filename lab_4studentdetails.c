#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int roll;
    float CGPA;
};
void readStudent(struct Student* student) {
    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", student->name);
    printf("Roll number: ");
    scanf("%d", &student->roll);
    printf("CGPA: ");
    scanf("%f", &student->CGPA);
}
void displayStudent(const struct Student* student) {
    printf("Student details:\n");
    printf("Name: %s\n", student->name);
    printf("Roll number: %d\n", student->roll);
    printf("CGPA: %.2f\n", student->CGPA);
}
int compareRoll(const void* a, const void* b) {
    const struct Student* s1 = (const struct Student*)a;
    const struct Student* s2 = (const struct Student*)b;
    return s1->roll - s2->roll;
}
int main() {
    int numStudents;
    printf("Enter the number of students: ");#include <stdio.h>
#include <stdlib.h>

// Define the Student structure
struct Student {
    char name[50];
    int roll;
    float CGPA;
};

// Function to read a Student object
void readStudent(struct Student* student) {
    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", student->name);
    printf("Roll number: ");
    scanf("%d", &student->roll);
    printf("CGPA: ");
    scanf("%f", &student->CGPA);
}

// Function to display a Student object
void displayStudent(const struct Student* student) {
    printf("Student details:\n");
    printf("Name: %s\n", student->name);
    printf("Roll number: %d\n", student->roll);
    printf("CGPA: %.2f\n", student->CGPA);
}

// Comparator function for sorting based on roll number
int compareRoll(const void* a, const void* b) {
    const struct Student* s1 = (const struct Student*)a;
    const struct Student* s2 = (const struct Student*)b;
    return s1->roll - s2->roll;
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for an array of Student structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Read details for each student
    for (int i = 0; i < numStudents; ++i) {
        readStudent(&students[i]);
    }

    // Display details for each student
    for (int i = 0; i < numStudents; ++i) {
        displayStudent(&students[i]);
    }

    // Sort the array based on roll number
    qsort(students, numStudents, sizeof(struct Student), compareRoll);

    // Display sorted details
    printf("\nSorted student details (by roll number):\n");
    for (int i = 0; i < numStudents; ++i) {
        displayStudent(&students[i]);
    }

    // Free allocated memory
    free(students);

    return 0;
}

    scanf("%d", &numStudents);
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    for (int i = 0; i < numStudents; ++i) {
        readStudent(&students[i]);
    }
    for (int i = 0; i < numStudents; ++i) {
        displayStudent(&students[i]);
    }
    qsort(students, numStudents, sizeof(struct Student), compareRoll);
        printf("\nSorted student details (by roll number):\n");
    for (int i = 0; i < numStudents; ++i) {
        displayStudent(&students[i]);
    }
    free(students);
    return 0;
}
