#include <stdio.h>
#include <limits.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void replace_elements(int matrix[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        for (int j = 0; j < COLS; j++) {
            if (i == j) {
                result[i][j] = 0;
            } else if (i > j) {
                if (matrix[i][j] > max_value) {
                    max_value = matrix[i][j];
                }
                result[i][j] = max_value;
            } else {
                if (matrix[i][j] < min_value) {
                    min_value = matrix[i][j];
                }
                result[i][j] = min_value;
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS];
    int result[ROWS][COLS];

    printf("Enter the elements of matrix A of size %dx%d:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    clock_t start = clock();

    replace_elements(matrix, result);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Resultant matrix B of size %dx%d:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
