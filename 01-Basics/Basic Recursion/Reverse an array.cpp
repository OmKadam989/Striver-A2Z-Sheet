/* Problem link:
   https://leetcode.com/problems/reverse-string/description/

Problem:
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Examples:

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

class Solution {
public:
    // Recursive helper function
    void reverseS(int i, vector<char> &s, int n) {
        // Base case: stop when we reach or cross the middle
        if (i >= n / 2) return;

        // Swap current character with its mirror position
        // Example: for "hello", swap 'h' with 'o'
        swap(s[i], s[n - i - 1]);

        // Recursive call for the next index
        // Example: after fixing 'h' and 'o', move to swap 'e' and 'l'
        reverseS(i + 1, s, n);
    }

    void reverseString(vector<char>& s) {
        int n = s.size();
        // Start recursion from index 0
        // Recursively swap characters until the middle is reached
        reverseS(0, s, n);
    }
};
