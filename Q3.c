#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void toggle_case(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    clock_t start = clock();

    toggle_case(str);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    printf("Toggled string: %s", str);

    return 0;
}
