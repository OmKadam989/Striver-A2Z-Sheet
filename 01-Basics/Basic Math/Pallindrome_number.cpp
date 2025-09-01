/* Problem link:
   https://leetcode.com/problems/palindrome-number/description/
*/

/*
Problem:
Given an integer x, return true if x is a palindrome, and false otherwise.

A palindrome is a number that reads the same backward as forward.

Examples:

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads the same from left to right and right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. 
Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left, which is not the same as 10.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false; 

        int original = x;       // Store original number
        long long digit = 0;    // Use long long to avoid overflow

        // Reverse the number
        while (x) {
            int rem = x % 10;          // Extract last digit
            digit = digit * 10 + rem;  // Build reversed number
            x /= 10;                   // Remove last digit
        }

        // Compare reversed number with original
        return digit == original;
    }
};
