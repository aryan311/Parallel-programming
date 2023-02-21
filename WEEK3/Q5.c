#include <stdio.h>
#include <omp.h>
#define SIZE 9
void reverseDigits(int *input, int *output, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        int num = input[i];
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + (num % 10);
            num /= 10;
        }
        output[i] = reversed;
    }
}
int main() {
    int input[SIZE];
    int output[SIZE];
  printf("Enter 9 numbers\n");
  for (int i = 0; i < 9; i++) {
    scanf("%d", &input[i]);
  }
    reverseDigits(input, output, SIZE);
    printf("Input array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
    printf("Output array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
    return 0;
}
