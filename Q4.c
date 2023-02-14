#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char str[100];
    printf("Enter a word: ");
    scanf("%s", str);

    int len = strlen(str);
    char pattern[100];
    int index = 0;

    clock_t start = clock();

    for (int i = 0; i < len; i++) {
        pattern[index++] = str[i];
        for (int j = 0; j < i; j++) {
            pattern[index++] = str[i];
        }
    }
    pattern[index] = '\0';

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    printf("Pattern: %s\n", pattern);

    return 0;
}
