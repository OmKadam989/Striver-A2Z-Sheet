/* Problem link:
   https://www.geeksforgeeks.org/problems/prime-number2314/1
*/

/*
Problem:
Given a positive integer n, check whether it is a prime number or not.

A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.

Examples:

Example 1:
Input: n = 7
Output: true
Explanation: 7 has exactly two divisors: 1 and 7, making it a prime number.

Example 2:
Input: n = 25
Output: false
Explanation: 25 has divisors: 1, 5, and 25 → more than two divisors, hence not prime.
*/

class Solution {
  public:
    bool isPrime(int n) {
        // 1 is not a prime number
        if (n == 1) return false;

        // 2 is the only even prime number
        if (n == 2) return true;

        // Check divisibility from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) 
                return false;  // Found a divisor, not prime
        }

        return true;  // No divisors found, number is prime
    }
};
