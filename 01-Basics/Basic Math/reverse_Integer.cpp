/* Problem link
https://leetcode.com/problems/reverse-integer/description/
*/

/*
Problem:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range 
[-2^31, 2^31 - 1], then return 0.

Examples:
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        long long digit = 0;   // Use long long to avoid overflow during calculation

        // Process each digit
        while(x) {
            int rem = x % 10;          // Extract the last digit
            digit = digit * 10 + rem;  // Append digit to the reversed number
            x /= 10;                   // Remove the last digit
        }

        // Check for 32-bit integer overflow
        if(digit < INT_MIN || digit > INT_MAX) 
            return 0;

        return digit;   // Safe to return within range
    }
};

