#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int a[N] = {3, 5, 2, 8, 1, 6, 4, 9, 7, 0};
    int even_sum = 0, odd_sum = 0;

    #pragma omp parallel num_threads(2)
    {
        int thread_id = omp_get_thread_num();

        #pragma omp sections
        {
            #pragma omp section
            {
                for (int i = 0; i < N; i++) {
                    if (a[i] % 2 == 0) {
                        #pragma omp atomic
                        even_sum += a[i];
                    }
                }
                printf("Thread %d: Even sum = %d\n", thread_id, even_sum);
            }

            #pragma omp section
            {
                for (int i = 0; i < N; i++) {
                    if (a[i] % 2 != 0) {
                        #pragma omp atomic
                        odd_sum += a[i];
                    }
                }
                printf("Thread %d: Odd sum = %d\n", thread_id, odd_sum);
            }
        }
    }

    printf("Total even sum = %d\n", even_sum);
    printf("Total odd sum = %d\n", odd_sum);

    return 0;
}
