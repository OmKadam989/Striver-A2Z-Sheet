/* Problem link:
   https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
*/

/*
Problem:
Given a positive integer n, the task is to find the sum of all divisors of numbers 
from 1 to n.

Formally:
F(i) = sum of divisors of i
Answer = F(1) + F(2) + ... + F(n)

Examples:

Example 1:
Input: n = 5
Output: 21
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
F(5) = 1 + 5 = 6
Total = 1 + 3 + 4 + 7 + 6 = 21
*/

class Solution {
  public:
    long long sumOfDivisors(long long n) {
        long long sum = 0;  // Store final result

        // Brute force: check each number from 1 to n
        for (long long i = 1; i <= n; i++) {
            // For each i, find its divisors
            for (long long j = 1; j <= i; j++) {
                if (i % j == 0) {   // j is a divisor of i
                    sum += j;
                }
            }
        }

        return sum;
    }
};
