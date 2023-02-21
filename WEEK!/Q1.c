#include <stdio.h>
#include <time.h>

void reverse_digits(int arr[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int rev_num = 0;
        while (num > 0) {
            int digit = num % 10;
            rev_num = rev_num * 10 + digit;
            num /= 10;
        }
        arr[i] = rev_num;
    }
}

int main() {
    int arr[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};

    clock_t start = clock();

    reverse_digits(arr, 9);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    printf("Reversed array: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

