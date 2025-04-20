#include <stdio.h>

void printMatrix(int matrix[2][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int A[2][3], int B[3][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int C[3][2], int C_T[2][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            C_T[j][i] = C[i][j];
        }
    }
}

void addMatrices(int A[2][2], int result[2][2], int D[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            D[i][j] = A[i][j] + result[i][j];
        }
    }
}

int main() {
    int A[2][2] = {{6, 4}, {8, 3}};
    int B[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int C[3][2] = {{2, 4}, {1, 3}, {5, 6}};

    int result[2][2];
    int C_T[2][3];
    int D[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            B[i][j] *= 3;
        }
    }

    transposeMatrix(C, C_T);
    multiplyMatrices(B, C_T, result);
    addMatrices(A, result, D);

    printf("Matrix D is: \n");
    printMatrix(D, 2, 2);

    return 0;
}