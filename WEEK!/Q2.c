#include <stdio.h>
#include <time.h>

int main() {
    double A, B;
    printf("Enter the first number (A): ");
    scanf("%lf", &A);
    printf("Enter the second number (B): ");
    scanf("%lf", &B);

    clock_t start = clock();

    printf("A + B = %.2f\n", A + B);
    printf("A - B = %.2f\n", A - B);
    printf("A * B = %.2f\n", A * B);
    printf("A / B = %.2f\n", A / B);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
