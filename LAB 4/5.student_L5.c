#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int rollNumber;
    float CGPA;
} Student;

// Function to read a Student object
void readStudent(Student *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter roll number: ");
    scanf("%d", &s->rollNumber);
    printf("Enter CGPA: ");
    scanf("%f", &s->CGPA);
}

// Function to display a Student object
void displayStudent(Student *s) {
    printf("Name: %s, Roll Number: %d, CGPA: %.2f\n", s->name, s->rollNumber, s->CGPA);
}

// Function to sort an array of Students by roll number
void sortStudents(Student *students, int n) {
    int i,j;
    Student temp;
    for ( i = 0; i < n-1; i++) {
        for ( j = i+1; j < n; j++) {
            if (students[i].rollNumber > students[j].rollNumber) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n,i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n students
    Student *students = (Student *)malloc(n * sizeof(Student));

    // Read students
    for (i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1);
        readStudent(&students[i]);
    }

    // Sort students by roll number
    sortStudents(students, n);

    // Display sorted students
    printf("\nStudents sorted by roll number:\n");
    for (i = 0; i < n; i++) {
        displayStudent(&students[i]);
    }

    // Free the allocated memory
    free(students);

    return 0;
}
