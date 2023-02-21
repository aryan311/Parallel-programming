#include <stdio.h>
#include <omp.h>

#define N 4

int main() {
    int A[N] = {1, 2, 3, 4};
    int B[N] = {5, 6, 7, 8};
    int C[N];

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        // Addition
        C[i] = A[i] + B[i];

        // Subtraction
        C[i + N] = A[i] - B[i];

        // Multiplication
        C[i + 2 * N] = A[i] * B[i];

        // Division
        C[i + 3 * N] = A[i] / B[i];
    }

    printf("A + B = [%d, %d, %d, %d]\n", C[0], C[1], C[2], C[3]);
    printf("A - B = [%d, %d, %d, %d]\n", C[N], C[N + 1], C[N + 2], C[N + 3]);
    printf("A * B = [%d, %d, %d, %d]\n", C[2 * N], C[2 * N + 1], C[2 * N + 2], C[2 * N + 3]);
    printf("A / B = [%d, %d, %d, %d]\n", C[3 * N], C[3 * N + 1], C[3 * N + 2], C[3 * N + 3]);

    return 0;
}
