// Reverses an input string.
fn reverse_string(input: &mut String) -> String {
    let mut ans: String = String::new();
    while !input.is_empty() {
        ans.push(input.pop().unwrap());
    }
    return ans;
}

// Counts the number of ones in the binary representation
// of an integer.
fn count_ones(input: &mut u32) -> u32 {
    let mut count: u32 = 0;
    while *input > 0 {
        count += *input % 2;
        *input = *input >> 1;
    }
    return count;
}

// Returns the fibonacci sequence of length n. Iterative method.
fn fibonacci(n: u32) -> Vec<u32> {
    let mut ans: Vec<u32> = vec!();
    if n == 1 {
        ans.push(1);
    } else if n == 2 {
        ans.push(1);
        ans.push(1);
    } else if n != 0 {
        let n_usize: usize = n.try_into().unwrap();
        ans.push(1);
        ans.push(1);
        for i in 2usize..n_usize {
            ans.push(ans[i-2] + ans[i-1])
        }
    }
    return ans
}

// Classic fizzbuzz implementation.
fn fizzbuzz(n: u32) -> Vec<String> {
    let mut ans: Vec<String> = vec!();
    for i in 1..n+1 {
        let mut result: String = String::new();
        if i % 3 == 0 {
            result.push_str("Fizz");
        }
        if i % 5 == 0 {
            result.push_str("Buzz");
        }
        if result.is_empty() {
            result.push_str(&i.to_string()[..]);
        }
        ans.push(result);
    }
    return ans;
}

// Returns the two numbers in input that add up to target.
fn two_sum(input: Vec<u32>, target: u32) -> Vec<u32> {
    let mut ans: Vec<u32> = vec!();
    for i in 0..input.len() {
        if input[i] < target {
            for j in i..input.len() {
                if input[i] + input[j] == target {
                    ans.push(input[i]);
                    ans.push(input[j]);
                    return ans;
                }
            }
        }
    }
    return ans;
}

// Returns whether or not the input is a palindrome.
fn is_palindrome(x: i32) -> bool {
    if x < 0 {
        return false;
    }
    let mut temp = x;
    let mut digits: Vec<i32> = Vec::new();
    while temp > 0 {
        let digit = temp % 10;
        digits.push(digit);
        temp = temp / 10;
    }
    for i in 0..(digits.len()/2) {
        if digits[i] != digits[digits.len() - i - 1] {
            return false;
        }
    }
    return true;
}

fn main() {
    let mut input: String = String::from("Hello world");
    let ans = reverse_string(&mut input);
    println!("{}", ans);

    let mut input2: u32 = 511u32;
    println!("{}", count_ones(&mut input2));

    let input3: u32 = 10u32;
    println!("{:?}", fibonacci(input3));

    let input4: u32 = 32u32;
    println!("{:?}", fizzbuzz(input4));

    let input5: Vec<u32> = vec!(5, 3, 5, 6, 7, 4);
    let input6: u32 = 7;
    println!("{:?}", two_sum(input5, input6));

    let input7: i32 = 121121;
    println!("{:?}", is_palindrome(input7));
}
