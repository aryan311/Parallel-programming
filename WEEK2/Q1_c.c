#include <stdio.h>
#include <omp.h>

int main()
{
    int num_threads, thread_id;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10];
    
    #pragma omp parallel private(num_threads, thread_id)
    {
        num_threads = omp_get_num_threads();
        thread_id = omp_get_thread_num();
        
        printf("Thread %d of %d is doing work.\n", thread_id, num_threads);
        
        #pragma omp for
        for (int i = 0; i < 10; i++) {
            b[i] = a[i] * thread_id;
        }
    }
    
    printf("Resultant array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", b[i]);
    }
    
    return 0;
}
