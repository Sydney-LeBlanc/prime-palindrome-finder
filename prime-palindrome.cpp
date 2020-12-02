//
// Student name: Sydney LeBlanc
//
// SYDE 121 assignment: 2
// file name: prime_palindrome
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: prime finder
// Purpose: Determine all the prime numbers and specify if they are palindromes
// or odd below a specified integer
//
// Due date: October 9, 2020
//***************************************************

/*
 Program will work for any integer greater than zero, and less than 2^31 9max of int)
 Tested entry values: 929, 5000, 80111, 150000, 500000.
 Confirmed results through an online encyclopedia, by confirming at least 5 primes,
 5 palindromes and 5 odd digit sums for each entry value.
 Values greater than 500000 take a while to compute, are not reasonable for the user.
 */

#include <iostream>
using namespace std;

void set_entry_value(int& entry_value);
// PURPOSE: Allows the user to set the entry_value
//    INPUTS: entry_value - integer value reference that will contain the inputted entry_value
//    OUTPUTS: nothing; value is returned by reference

bool is_prime(int value);
// PURPOSE: Tests if the integer value is a prime number
//    INPUTS: value – integer value to be tested
//    OUTPUTS: returns true if it is prime, returns false if not

bool is_palindrome(int value);
// PURPOSE: Tests if the integer value is a palindrome
//    INPUTS: value – integer value to be tested
//    OUTPUTS: returns true if it is palindrome, returns false is not

bool is_odd(int value);
// PURPOSE: tests if the sum of the digits of the intger value are odd
//    INPUTS: value – integer value to be tested
//    OUTPUTS: returns true if the sum of digits is odd, returns false if they are even

void set_entry_value(int& entry_value) {
    //step1. allow the user to enter a value that is greater than zero
    while (entry_value <= 1) {
        cout << " Enter an integer to find all the primes equal or less that it: ";
        cin >> entry_value;
    }
}

bool is_prime(int value) {
    //step1. process all values less than entry_value and return true
    // if they are prime
    for (int divisor = 2; divisor < value; divisor++) {
        if (value % divisor == 0) {
            return false;
        }
    }
    return true;
}

bool is_palindrome(int value) {
    // declare and initialize variables
    int original_value = value, value_reverse = 0, remainder = 0;
    
    // step1. process value to find the reverse digit order
    do {
        remainder = value % 10;
        value_reverse = value_reverse * 10 + remainder;
        value = value / 10;
    } while (value > 0);
    
    // step2. return true if order of digits is the same in the reverse order
    if (original_value == value_reverse) {
        return true;
    }
    else {
        return false;
    }
}

bool is_odd(int value) {
    // declare and intialize variables
    int remainder = 0, digits_sum = 0;
    int digit_column = 1;
    
    // step1. process value to add up the digits of the value
    do {
        remainder = value % 10;
        digits_sum = digits_sum + remainder;
        digit_column = digit_column * 10;
        value = value / 10;
    } while (value > 0);
    
    // step2. Return false if the sum of digits is even
    if (digits_sum % 2 == 0) {
        return false;
    }
    else {
        return true;
    }
}

void execute_prime_finder();
//PURPOSE: Runs the steps of the specified program

void execute_prime_finder() {
    // delcare and initialize variables
   int entry_value = 0;
    // step1. Allow user to set maximum value
    set_entry_value(entry_value);
    
    // step2. Outputs computed stats
    for (int test_integer= 1; test_integer <= entry_value; test_integer++) {
        // step2.1 first check if prime
        if (is_prime(test_integer)) {
            cout << test_integer;
            // step2.11 checks if it is also a palindrome
            if (test_integer < 10000 && is_palindrome(test_integer)) {
                cout << " (Palindrome)";
            }
            // step2.12 checks if it the digits sum are also odd
            if (test_integer < 100000 && is_odd(test_integer)) {
                cout << " (Odd Digit Sum)";
            }
            cout << endl;
        }
    }
}

int main() {
    execute_prime_finder();
}
