#include <stdio.h>
#include <omp.h>

int main() {
    int a = 5, b = 3, result = 0;
    omp_set_num_threads(4);
    
    #pragma omp parallel shared(a, b, result)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                result = a + b;
                printf("Thread %d: %d + %d = %d\n", omp_get_thread_num(), a, b, result);
            }
            #pragma omp section
            {
                result = a - b;
                printf("Thread %d: %d - %d = %d\n", omp_get_thread_num(), a, b, result);
            }
            #pragma omp section
            {
                result = a * b;
                printf("Thread %d: %d * %d = %d\n", omp_get_thread_num(), a, b, result);
            }
            #pragma omp section
            {
                result = a / b;
                printf("Thread %d: %d / %d = %d\n", omp_get_thread_num(), a, b, result);
            }
        }
    }
    
    return 0;
}

