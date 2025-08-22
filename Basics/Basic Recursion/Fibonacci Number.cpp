/* Problem link:
   https://leetcode.com/problems/fibonacci-number/description/
*/

/*
Problem:
The Fibonacci numbers are defined as:
F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1

Given n, return F(n).

Examples:
Input: n = 2
Output: 1   (F(2) = F(1) + F(0) = 1 + 0)

Input: n = 3
Output: 2   (F(3) = F(2) + F(1) = 1 + 1)
*/

class Solution {
public:
    // Recursive function to calculate nth Fibonacci number
    int fibo(int n) {
        // Base cases: F(0) = 0, F(1) = 1
        if (n <= 1) return n;

        // Recursive case: F(n) = F(n-1) + F(n-2)
        return fibo(n - 1) + fibo(n - 2);
    }

    int fib(int n) {
        // Just call our recursive helper
        return fibo(n);
    }
};
