#include <stdio.h>

// Function to read a matrix
void readMatrix(int matrix[][10], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][10], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int resultMatrix[][10], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < colFirst; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int rowFirst, colFirst, rowSecond, colSecond;

    // Input dimensions of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);

    // Input dimensions of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);

    // Check if matrices can be multiplied
    if (colFirst != rowSecond) {
        printf("Error! Column of the first matrix is not equal to row of the second matrix.\n");
        return -1;
    }

    int firstMatrix[10][10], secondMatrix[10][10], resultMatrix[10][10];

    // Read matrices
    readMatrix(firstMatrix, rowFirst, colFirst);
    readMatrix(secondMatrix, rowSecond, colSecond);

    // Display matrices
    printf("First ");
    displayMatrix(firstMatrix, rowFirst, colFirst);
    printf("Second ");
    displayMatrix(secondMatrix, rowSecond, colSecond);

    // Multiply matrices
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rowFirst, colFirst, rowSecond, colSecond);

    // Display result
    printf("Resultant ");
    displayMatrix(resultMatrix, rowFirst, colSecond);

    return 0;
}
