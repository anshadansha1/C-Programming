/*PROGRAM 1_6 : TWO DIMENTIONAL MATRIX USING FUNCTIONS:
a.Addition
b.Subtraction
c.Multiplication
*/
#include <stdio.h>
#define MAX_SIZE 10
int i,j,k;
void inputMat(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void dispMat(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMat(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subMat(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multMat(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
	
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int determinant(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (k = 0; k < n; k++) {
            int submatrix[MAX_SIZE][MAX_SIZE];
            int subi = 0;
            for (i = 1; i < n; i++) {
                int subj = 0;
                for (j = 0; j < n; j++) {
                    if (j == k) continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (k % 2 == 0 ? 1 : -1) * matrix[0][k] * determinant(submatrix, n - 1);
        }
        return det;
    }
}

void transMat(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    inputMat(mat1, rows1, cols1);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    inputMat(mat2, rows2, cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("\nMatrix addition, subtraction, and multiplication are not possible.\n");
    } else {
        // Addition
        addMat(mat1, mat2, result, rows1, cols1);
        printf("\nMatrix Addition:\n");
        dispMat(result, rows1, cols1);

        // Subtraction
        subMat(mat1, mat2, result, rows1, cols1);
        printf("\nMatrix Subtraction:\n");
        dispMat(result, rows1, cols1);

        // Multiplication
        multMat(mat1, mat2, result, rows1, cols1, cols2);
        printf("\nMatrix Multiplication:\n");
        dispMat(result, rows1, cols2);
    }

    // Determinant
    if (rows1 == cols1) {
        int det = determinant(mat1, rows1);
        printf("\n\nDeterminant of matrix 1: %d\n", det);
    } else {
        printf("Determinant can only be calculated for square matrices.\n");
    }
        if (rows2 == cols2) {
        int det = determinant(mat2, rows2);
        printf("\nDeterminant of matrix 2: %d\n", det);
    } else {
        printf("Determinant can only be calculated for square matrices.\n");
    }


    // Transpose
    int transpose[MAX_SIZE][MAX_SIZE];
    transMat(mat1, transpose, rows1, cols1);
    printf("\n\nTranspose of matrix 1:\n");
    dispMat(transpose, cols1, rows1);

    transMat(mat2, transpose, rows2, cols2);
    printf("\nTranspose of matrix 1:\n");
    dispMat(transpose, cols2, rows2);

    return 0;
}
