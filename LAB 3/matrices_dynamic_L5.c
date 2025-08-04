#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int i;
    int *matrix = (int *)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free the allocated memory for a matrix
void freeMatrix(int **matrix, int rows) {
    int i ;
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read a matrix
void readMatrix(int **matrix, int rows, int cols) {
    int i ,j;
    printf("Enter the elements of the matrix:\n");
    for ( i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    int i ,j;
    printf("Matrix:\n");
    for ( i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
int** multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int i ,j,k;
    int **product = allocateMatrix(rows1, cols2);

    for ( i = 0; i < rows1; i++) {
        for ( j = 0; j < cols2; j++) {
            product[i][j] = 0;
            for ( k = 0; k < cols1; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return product;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input the dimensions of the first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Input the dimensions of the second matrix
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible with these dimensions.\n");
        return 1;
    }

    // Allocate memory for the matrices
    int **matrix1 = allocateMatrix(rows1, cols1);
    int **matrix2 = allocateMatrix(rows2, cols2);

    // Read the matrices
    printf("Enter the elements of the first matrix:\n");
    readMatrix(matrix1, rows1, cols1);
    printf("Enter the elements of the second matrix:\n");
    readMatrix(matrix2, rows2, cols2);

    // Display the matrices
    printf("First matrix:\n");
    displayMatrix(matrix1, rows1, cols1);
    printf("Second matrix:\n");
    displayMatrix(matrix2, rows2, cols2);

    // Multiply the matrices
    int **product = multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);

    // Display the product matrix
    printf("Product of the matrices:\n");
    displayMatrix(product, rows1, cols2);

    // Free the allocated memory
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(product, rows1);

    return 0;
}
