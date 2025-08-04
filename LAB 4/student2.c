#include <stdio.h>
#include <stdlib.h>

// Define the structure for Date of Birth
typedef struct {
    int day;
    int month;
    int year;
} DOB;

// Define the structure for Address
typedef struct {
    int houseNumber;
    int zipCode;
    char state[30];
} Address;

// Define the structure for Student
typedef struct {
    char name[50];
    DOB *dob;
    Address address;
} STUDENT;

// Function to read student data
void readStudentData(STUDENT *student) {
    printf("Enter name: ");
    scanf(" %[^\n]", student->name);

    student->dob = (DOB *)malloc(sizeof(DOB));
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &student->dob->day, &student->dob->month, &student->dob->year);

    printf("Enter house number: ");
    scanf("%d", &student->address.houseNumber);
    printf("Enter zip code: ");
    scanf("%d", &student->address.zipCode);
    printf("Enter state: ");
    scanf(" %[^\n]", student->address.state);
}

// Function to display student data
void displayStudentData(STUDENT *student) {
    printf("Name: %s\n", student->name);
    printf("Date of Birth: %02d/%02d/%04d\n", student->dob->day, student->dob->month, student->dob->year);
    printf("Address: House Number %d, Zip Code %d, State %s\n", student->address.houseNumber, student->address.zipCode, student->address.state);
}

int main() {
    int n,i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for N students
    STUDENT *students = (STUDENT *)malloc(n * sizeof(STUDENT));

    // Read data for each student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        readStudentData(&students[i]);
    }

    // Display data for each student
    printf("\nStudent Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudentData(&students[i]);
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(students[i].dob);
    }
    free(students);

    return 0;
}
