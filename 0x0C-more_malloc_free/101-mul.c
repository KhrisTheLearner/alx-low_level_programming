#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void multiply(char* num1, char* num2);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    char* num1 = argv[1];
    char* num2 = argv[2];

    for (int i = 0; i < strlen(num1); i++) {
        if (!isdigit(num1[i])) {
            printf("Error\n");
            return 98;
        }
    }

    for (int i = 0; i < strlen(num2); i++) {
        if (!isdigit(num2[i])) {
            printf("Error\n");
            return 98;
        }
    }

    multiply(num1, num2);

    return 0;
}

void multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int* result = (int*) malloc(sizeof(int) * (len1 + len2));

    // Initialize the result array
    for (int i = 0; i < len1 + len2; i++) {
        result[i] = 0;
    }

    // Multiply each digit of num1 with each digit of num2
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + product;
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    // Remove leading zeros
    int i = 0;
    while (result[i] == 0 && i < len1 + len2 - 1) {
        i++;
    }

    // Print the result
    for (; i < len1 + len2; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    free(result);
}
