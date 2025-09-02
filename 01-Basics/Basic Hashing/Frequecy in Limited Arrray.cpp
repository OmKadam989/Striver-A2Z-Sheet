/* Problem link:
   https://leetcode.com/problems/reverse-string/description/
*/

/*
Problem:
Write a function that reverses a string. The input string is given as an array of characters `s`.
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
    // Recursive helper function to reverse the string
    void reverseS(int i, vector<char> &s, int n) {
        // Base case: stop recursion when we've reached/passed the middle
        if (i >= n / 2) return;

        // Swap the current character with its mirror from the end
        swap(s[i], s[n - i - 1]);

        // Recursive call: move towards the middle
        reverseS(i + 1, s, n);
    }

    // Main function to reverse the string
    void reverseString(vector<char>& s) {
        int n = s.size();
        reverseS(0, s, n);  // Start recursion from index 0
    }
};
`