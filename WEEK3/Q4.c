#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
const int M = 4;
const int N = 4;
int A[M][N] = {
{1, 2, 3, 4},
{6, 5, 8, 3},
{2, 4, 10, 1},
{9, 1, 2, 5}
};
int B[M][N];
int D[M][N];
#pragma omp parallel for shared(A, B, D)
for (int i = 0; i < M; i++) {
for (int j = 0; j < N; j++) {
if (i == 0 || i == M-1 || j == 0 || j == N-1) {
B[i][j] = A[i][j];
} else {
B[i][j] = ~A[i][j] + 2;
}
if (i == j) {
D[i][j] = 1;
} else {
D[i][j] = abs(i - j) + 1;
}
}
}
printf("Matrix A:\n");
for (int i = 0; i < M; i++) {
for (int j = 0; j < N; j++) {
printf("%d ", A[i][j]);
}
printf("\n");
}
printf("Matrix B:\n");
for (int i = 0; i < M; i++) {
for (int j = 0; j < N; j++) {
printf("%d ", B[i][j]);
}
printf("\n");
}
printf("Matrix D:\n");
for (int i = 0; i < M; i++) {
for (int j = 0; j < N; j++) {
printf("%d ", D[i][j]);
}
printf("\n");
}
return 0;
}
