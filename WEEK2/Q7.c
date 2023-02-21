#include <stdio.h>
#include <omp.h>

int main() {
    char str[] = "Hello";
    int n = sizeof(str) / sizeof(str[0]);
    int tid;
    
    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        printf("Thread %d: ", tid);
        
        for (int i = tid; i < n; i += omp_get_num_threads()) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 'a' + 'A';
            }
            else if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }
        }
        
        printf("%s\n", str);
    }
    
    return 0;
}
