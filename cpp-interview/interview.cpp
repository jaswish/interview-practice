#include <stdio.h>
#include "string.h"

// Reverses an input string.
void reverse_string(char* input) {
    for(int i = 0; i < strlen(input) / 2; i++) {
        input[strlen(input) - i - 1] += input[i];
        input[i] = input[strlen(input) - i - 1] - input[i];
        input[strlen(input) - i - 1] -= input[i];
    }
}

// Counts the number of ones in the binary representation
// of an integer.
unsigned int count_ones(unsigned int input) {
    int count = 0;
    while(input > 0) {
        count += input % 2;
        input = input >> 1;
    }
    return count;
}

int main() {
    char input[30] = "Hello world";
    reverse_string(input);
    printf("%s\n", input);

    printf("%d\n", count_ones(511));
}