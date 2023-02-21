#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_M 100
#define MAX_N 100

void calculate_time_taken(clock_t start_time);

int main() {
    char A[MAX_M][MAX_N];
    int B[MAX_M][MAX_N];
    char STR[MAX_M * MAX_N * 10];
    int m, n, i, j, k = 0;

    printf("Enter the size of matrix (M x N): ");
    scanf("%d %d", &m, &n);

    printf("Enter the character matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %c", &A[i][j]);
        }
    }

    printf("Enter the integer matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    clock_t start_time = clock();

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int repeat = B[i][j];
            while (repeat--) {
                STR[k++] = A[i][j];
            }
        }
    }

    STR[k] = '\0';

    printf("The output string is: %s\n", STR);

    calculate_time_taken(start_time);

    return 0;
}

void calculate_time_taken(clock_t start_time) {
    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
}
