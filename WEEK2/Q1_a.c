#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = 4;
    int thread_id, i;

    #pragma omp parallel num_threads(num_threads)
    {
        thread_id = omp_get_thread_num();

        #pragma omp for
        for (i = 0; i < num_threads; i++) {
            printf("Thread %d is executing iteration %d\n", thread_id, i);
        }

        printf("Thread %d is done.\n", thread_id);
    }

    printf("All threads have completed.\n");

    return 0;
}


