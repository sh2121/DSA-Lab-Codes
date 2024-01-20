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
int main() {
    int rows, cols;
    printf("\nEnter the number of rows:");
    scanf("%d", &rows);
    printf("\nEnter the number of columns:");
    scanf("%d", &cols);

    int mat[100][100];
    printf("\nEnter the matrix elements:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    rotateMatrix(mat, rows, cols);
    printf("\nRotated Matrix is:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
