#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 5
void matrix_manipulation(int a[][N], int b[][N]) {
    #pragma omp parallel for shared(a,b)
    for (int i = 0; i < N; i++) {
        int row_min = a[i][0];
        int row_max = a[i][0];
        for (int j = 0; j < N; j++) {
            if (i == j) {
                b[i][j] = 0;
            } else if (i < j) {
                if (a[i][j] < row_min) {
                    row_min = a[i][j];
                }
                b[i][j] = row_min;
            } else {
                if (a[i][j] > row_max) {
                    row_max = a[i][j];
                }
                b[i][j] = row_max;
            }
        }
    }
}
int main() {
    int a[N][N];
    int b[N][N];
    // Initialize matrix A with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 10;
        }
    }
    matrix_manipulation(a, b);
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
