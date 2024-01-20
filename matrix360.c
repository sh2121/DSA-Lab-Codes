#include <stdio.h>

void rotateMatrix(int mat[][100], int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[rows - 1 - i][j];
            mat[rows - 1 - i][j] = temp;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void printMatrix(int mat[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int compareMatrices(int mat1[][100], int mat2[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int rows, cols;
    printf("\nEnter the number of rows:");
    scanf("%d", &rows);
    printf("\nEnter the number of columns:");
    scanf("%d", &cols);

    int originalMat[100][100], rotatedMat[100][100];
    printf("\nEnter the original matrix elements");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &originalMat[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotatedMat[i][j] = originalMat[i][j];
        }
    }
    rotateMatrix(rotatedMat, rows, cols);
    printf("\nOriginal Matrix is:");
    
    printMatrix(originalMat, rows, cols);
    printf("\nRotated Matrix:");
    printMatrix(rotatedMat, rows, cols);
    if (compareMatrices(originalMat, rotatedMat, rows, cols)) {
        printf("\nThe original matrix is equal to the rotated matrix");
    } else {
        printf("\nThe original matrix is not equal to the rotated matrix");
    }

    return 0;
}
