#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void matrix_mult(int *a, int *b, int *c, int n) {
    #pragma omp parallel for shared(a,b,c,n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i*n+k] * b[k*n+j];
            }
            c[i*n+j] = sum;
        }
    }
}
int main() {
    int n_sizes[] = {200, 400, 600, 800, 1000};
    int n_threads[] = {1, 4};
    // Run matrix multiplication with varying matrix sizes and number of threads
    for (int i = 0; i < 5; i++) {
        int n = n_sizes[i];
        int *a = (int*) malloc(n*n*sizeof(int));
        int *b = (int*) malloc(n*n*sizeof(int));
        int *c = (int*) malloc(n*n*sizeof(int));
        // Initialize matrices with random values
        for (int j = 0; j < n*n; j++) {
            a[j] = rand() % 10;
            b[j] = rand() % 10;
        }
        printf("Matrix size: %d x %d\n", n, n);
        for (int k = 0; k < 2; k++) {
            int num_threads = n_threads[k];
            double start_time = omp_get_wtime();
            // Set number of threads
            omp_set_num_threads(num_threads);
            // Multiply matrices
            matrix_mult(a, b, c, n);
            double end_time = omp_get_wtime();
            double elapsed_time = end_time - start_time;
            printf("  Number of threads: %d\n", num_threads);
            printf("  Elapsed time: %f seconds\n", elapsed_time);
        }
        free(a);
        free(b);
        free(c);
    }
    return 0;
}
