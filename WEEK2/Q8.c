#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int A[] = {10, 13, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int i, fibNum;
    #pragma omp parallel private(i, fibNum)
    {
        #pragma omp for
        for (i = 0; i < n; i++) {
            fibNum = fib(A[i]);
            printf("Fibonacci number for %d is %d, calculated by thread %d\n", A[i], fibNum, omp_get_thread_num());
        }
    }
    return 0;
}
