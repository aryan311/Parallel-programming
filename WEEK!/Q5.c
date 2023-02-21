#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char s1[100], s2[100], result[100];
    int len;

    printf("Enter two strings of the same length: \n");
    printf("S1: ");
    scanf("%s", s1);
    printf("S2: ");
    scanf("%s", s2);

    len = strlen(s1);

    clock_t start = clock();

    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            result[i] = s1[i];
        } else {
            result[i] = s2[i];
        }
    }
    result[len] = '\0';

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    printf("Resultant string: %s\n", result);

    return 0;
}
