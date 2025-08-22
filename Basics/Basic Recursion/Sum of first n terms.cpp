/* Problem link:
   https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1
*/

/*
Problem:
Given a number n, find the sum of the series:

1³ + 2³ + 3³ + … + n³

Examples:

Example 1:
Input: n = 5
Output: 225
Explanation: 1³ + 2³ + 3³ + 4³ + 5³ 
           = 1 + 8 + 27 + 64 + 125 
           = 225

Example 2:
Input: n = 3
Output: 36
Explanation: 1³ + 2³ + 3³ = 1 + 8 + 27 = 36
*/

class Solution {
  public:
    // Recursive helper function
    int sumOf(int n, int sum) {
        if (n == 0) return sum;              // Base case: stop when n reaches 0
        
        sum = sum + (n * n * n);             // Add cube of current number
        return sumOf(n - 1, sum);            // Recursive call for (n-1)
    }

    // Function to return sum of series
    int sumOfSeries(int n) {
        return sumOf(n, 0);                  // Start recursion with sum = 0
    }
};
