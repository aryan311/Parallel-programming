#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int sequential_search(int *array, int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int parallel_search(int *array, int size, int target, int num_threads) {
    int i, chunk_size;
    int found = -1;
    
    #pragma omp parallel num_threads(num_threads)
    {
        int start, end, tid;
        tid = omp_get_thread_num();
        chunk_size = (size + num_threads - 1) / num_threads;
        start = tid * chunk_size;
        end = (tid + 1) * chunk_size;
        if (end > size) {
            end = size;
        }
        
        #pragma omp barrier
        
        for (i = start; i < end; i++) {
            if (array[i] == target) {
                found = i;
                break;
            }
        }
    }
    
    return found;
}

int main(int argc, char **argv) {
    int max_size = 10000000;
    int target = 42;
    int num_threads, found;
    int *array;
    double start_time, end_time, elapsed_time;
    int i, j;
    
    // Generate random array sizes
    int num_sizes = 10;
    int sizes[num_sizes];
    srand(time(NULL));
    for (i = 0; i < num_sizes; i++) {
        sizes[i] = rand() % max_size + 1;
    }
    
    // Run the search for each size and thread count
    double times[MAX_THREADS][num_sizes];
    double sequential_time;
    for (i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        array = malloc(size * sizeof(int));
        for (j = 0; j < size; j++) {
            array[j] = j;
        }
        
        sequential_time = 0.0;
        for (num_threads = 1; num_threads <= MAX_THREADS; num_threads++) {
            start_time = omp_get_wtime();
            found = parallel_search(array, size, target, num_threads);
            end_time = omp_get_wtime();
            elapsed_time = end_time - start_time;
            times[num_threads-1][i] = elapsed_time;
            
            if (num_threads == 1) {
                sequential_time = elapsed_time;
            }
        }
        
        // Calculate and print speed up and efficiency
        printf("Array size: %d\n", size);
        printf("Sequential time: %f seconds\n", sequential_time);
        printf("Threads\tParallel time\tSpeed up\tEfficiency\n");
        for (num_threads = 1; num_threads <= MAX_THREADS; num_threads++) {
            double parallel_time = times[num_threads-1][i];
            double speed_up = sequential_time / parallel_time;
            double efficiency = speed_up / num_threads;
            printf("%d\t%f\t%f\t%f\n", num_threads, parallel_time, speed_up, efficiency);
        }
        
        free(array);
    }
    
    return 0;
}