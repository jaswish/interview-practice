# Reverses an input string.
def reverse_string(input: str) -> str:
    for i in range(int(len(input)/2)):
        input = ''.join([input[0:i], 
                         input[len(input) - i - 1], 
                         input[(i+1):(len(input) - i - 1)], 
                         input[i], 
                         input[(len(input) - i):len(input)]])
    return input

# Counts the number of ones in the binary representation of
# an integer.
def count_ones(input: int) -> int:
    count = 0
    while input > 0:
        count += input % 2
        input = input >> 1
    return count

value = "Hello world"
print(reverse_string(value))

val = 511
print(count_ones(val))