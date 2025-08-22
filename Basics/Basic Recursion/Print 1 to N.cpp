/* Problem link:
   https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1
*/

/*
Problem:
Given a number n, print numbers from 1 to n in increasing order without using any loops.

You must use recursion to solve this problem.

Examples:

Example 1:
Input: n = 10
Output: 1 2 3 4 5 6 7 8 9 10

Example 2:
Input: n = 5
Output: 1 2 3 4 5
*/

class Solution {
  public:
    // Helper function to recursively print numbers
    void print(int n) {
        if (n == 0) return;      // Base case: stop when n becomes 0
        
        print(n - 1);            // Recursive call: print numbers till n-1
        cout << n << " ";        // Print current number
    }

    // Function to start printing from 1 to n
    void printNos(int n) {
        print(n);
    }
};
