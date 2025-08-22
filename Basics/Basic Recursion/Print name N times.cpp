/* Problem link:
   https://www.geeksforgeeks.org/problems/print-gfg-n-times/1
*/

/*
Problem:
Given an integer N, print "GFG" N times without using any loops. 
The solution must be implemented using recursion.

Examples:

Example 1:
Input: N = 5
Output: GFG GFG GFG GFG GFG

Example 2:
Input: N = 3
Output: GFG GFG GFG
*/

class Solution {
  public:
    // Helper function to recursively print "GFG"
    void print(int n) {
        if (n == 0) return;          // Base case: stop when n becomes 0
        
        cout << "GFG" << " ";        // Print "GFG"
        print(n - 1);                // Recursive call with reduced count
    }

    // Function to print "GFG" N times
    void printGfg(int N) {
        print(N);
    }
};
