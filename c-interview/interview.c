#include <stdio.h>
#include "string.h"

unsigned int count_ones(unsigned int input) {
    unsigned int count = 0;
    while(input > 0) {
        count += input % 2;
        input = input >> 1;
    }

    return count;
}

void reverse_string(char* input) {
    int i = 0;
    int len = strlen(input);
    for(i = 0; i < strlen(input) / 2; i++) {
        size_t second_pos = strlen(input) - i - 1;
        char temp = input[i];
        input[i] = input[second_pos];
        input[second_pos] = temp;
    }
}

int main() {
    char input[30] = "Hello";
    reverse_string(input);
    printf("%s\n", input);

    printf("%d\n", count_ones(511));

    return 0;
}