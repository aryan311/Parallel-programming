#include <stdio.h>
#include <omp.h>

int main() {
    int i, x, tid, nthreads;

    #pragma omp parallel private(i, tid, nthreads, x)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        x = tid + 1;

        for (i = 1; i <= nthreads; i++) {
            printf("Power of %d to %d is: %d\n", i, x, (int)pow(i, x));
        }
    }

    return 0;
}
