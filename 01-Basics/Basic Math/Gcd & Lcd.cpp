/* Problem link:
   https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
*/

/*
Problem:
Given two numbers a and b, find their Least Common Multiple (LCM) and Greatest Common Divisor (GCD).

Definitions:
- GCD (Greatest Common Divisor): The largest number that divides both a and b.
- LCM (Least Common Multiple): The smallest number that is a multiple of both a and b.

Examples:

Example 1:
Input: a = 14, b = 8
Output: [56, 2]
Explanation: 
GCD of 14 and 8 is 2
LCM of 14 and 8 is (14 * 8) / 2 = 56

Example 2:
Input: a = 4, b = 6
Output: [12, 2]
Explanation:
GCD of 4 and 6 is 2
LCM of 4 and 6 is (4 * 6) / 2 = 12
*/

class Solution {
  public:
    // Function to calculate GCD using Euclidean algorithm
    int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) 
                a = a % b;
            else 
                b = b % a;
        }
        return (a == 0) ? b : a;
    }

    // Function to return both LCM and GCD
    vector<int> lcmAndGcd(int a, int b) {
        int g = gcd(a, b);                // Compute GCD
        int l = (1LL * a * b) / g;        // Compute LCM (use 1LL to prevent overflow)
        return {l, g};                    // Return as vector [LCM, GCD]
    }
};
