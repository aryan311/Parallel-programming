#include <stdio.h>

#define M 4
#define N 4

int main() {
    int A[M][N], B[M][N], D[M][N];
    int i, j;

    printf("Enter matrix A:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Generate matrix B
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                B[i][j] = A[i][j];
            } else {
                B[i][j] = ~A[i][j];
            }
        }
    }

    // Generate matrix D
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                D[i][j] = A[i][j];
            } else {
                int min = A[i][0];
                int max = A[i][0];
                int k;

                for (k = 1; k < N; k++) {
                    if (A[i][k] < min) {
                        min = A[i][k];
                    }
                    if (A[i][k] > max) {
                        max = A[i][k];
                    }
                }

                if (j <= i) {
                    D[i][j] = max;
                } else {
                    D[i][j] = min;
                }
            }
        }
    }

    // Print matrix B
    printf("Matrix B:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Print matrix D
    printf("Matrix D:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
