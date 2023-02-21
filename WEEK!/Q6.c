#include <stdio.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void matrix_vector_product(int matrix[ROWS][COLS], int vector[COLS], int result[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        result[i] = 0;
        for (int j = 0; j < COLS; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int vector[COLS] = {1, 2, 3};
    int result[ROWS];

    clock_t start = clock();

    matrix_vector_product(matrix, vector, result);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Resultant vector: ");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
