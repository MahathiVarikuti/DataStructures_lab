#include <stdio.h>
#include <stdlib.h>

// Define a structure for Date of Birth
typedef struct {
    int day;
    int month;
    int year;
} DateOfBirth;

// Define a structure for Address
typedef struct {
    int houseNumber;
    int zipCode;
    char state[30];
} Address;

// Define a structure for Employee
typedef struct {
    char name[50];
    DateOfBirth dob;
    Address address;
} Employee;

// Function to read employee data
void readEmployeeData(Employee *emp) {
    printf("Enter name: ");
    scanf(" %[^\n]", emp->name);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &emp->dob.day, &emp->dob.month, &emp->dob.year);
    printf("Enter house number: ");
    scanf("%d", &emp->address.houseNumber);
    printf("Enter zip code: ");
    scanf("%d", &emp->address.zipCode);
    printf("Enter state: ");
    scanf(" %[^\n]", emp->address.state);
}

// Function to display employee data
void displayEmployeeData(Employee *emp) {
    printf("Name: %s\n", emp->name);
    printf("Date of Birth: %02d/%02d/%04d\n", emp->dob.day, emp->dob.month, emp->dob.year);
    printf("Address: House Number %d, Zip Code %d, State %s\n", emp->address.houseNumber, emp->address.zipCode, emp->address.state);
}

int main() {
    int n,i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Allocate memory for N employees
    Employee *employees = (Employee *)malloc(n * sizeof(Employee));

    // Read data for each employee
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        readEmployeeData(&employees[i]);
    }

    // Display data for each employee
    printf("\nEmployee Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        displayEmployeeData(&employees[i]);
    }

    // Free allocated memory
    free(employees);

    return 0;
}
