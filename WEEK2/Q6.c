#include <stdio.h>
#include <omp.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int start = 2, end = 10;
    int thread_count = 4;
    
    #pragma omp parallel for num_threads(thread_count)
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }
    return 0;
}

