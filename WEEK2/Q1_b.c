#include <stdio.h>
#include <omp.h>

int main()
{
    // First parallel region with 2 threads
    #pragma omp parallel num_threads(2)
    {
        printf("Hello World from thread %d in region 1\n", omp_get_thread_num());
    }

    // Second parallel region with 4 threads
    #pragma omp parallel num_threads(4)
    {
        printf("Hello World from thread %d in region 2\n", omp_get_thread_num());
    }

    return 0;
}
