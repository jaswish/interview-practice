#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// Counts the number of ones in the binary
// representation of an integer.
unsigned int count_ones(unsigned int input) {
    unsigned int count = 0;
    while(input > 0) {
        count += input % 2;
        input = input >> 1;
    }

    return count;
}

// Reverses an input string.
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Returns two numbers in nums whose sum is target.
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int* answer = malloc(2*sizeof(int));
    for(i = 0; i < numsSize; i++) {
        for(j = i+1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer;
            }
        }
    }

    return NULL;
}

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }

    int* digits = malloc(16*sizeof(int));
    int count = 0;
    while(x > 0) {
        int digit = x % 10;
        digits[count++] = digit;
        x /= 10;
    }

    int i;
    for(i = 0; i < count/2; i++) {
        if(digits[i] != digits[count - i - 1]) {
            free(digits);
            return false;
        }
    }

    free(digits);
    return true;
}

int main() {
    char input[30] = "Hello";
    reverse_string(input);
    printf("%s\n", input);

    printf("%d\n", count_ones(511));

    int two_sum_input[5] = {1, 2, 3, 4, 5};
    int returnSize = 0;
    int* answer = twoSum(two_sum_input, 5, 7, &returnSize);
    int i;
    printf("Answer for twoSum()\n");
    for(i = 0; i < returnSize; i++) {
        printf("%d\n", answer[i]);
    }
    free(answer);

    printf("Is it a palindrome? %d\n", isPalindrome(5237325));

    return 0;
}