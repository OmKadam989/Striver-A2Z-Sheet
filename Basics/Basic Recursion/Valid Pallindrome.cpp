/* Problem link:
   https://leetcode.com/problems/valid-palindrome/description/
*
Problem:
Given a string s, return true if it is a palindrome, or false otherwise.

Rules:
- Only alphanumeric characters are considered (ignore spaces, commas, etc).
- Case-insensitive (e.g., 'A' == 'a').

Examples:
Input:  "A man, a plan, a canal: Panama"
Output: true
Explanation: After removing non-alphanumeric and ignoring case, 
             it becomes "amanaplanacanalpanama", which is a palindrome.

Input:  "race a car"
Output: false
Explanation: After cleanup, it's "raceacar", which is not a palindrome.
*/

class Solution {
public:
    // Recursive helper function to check palindrome
    bool helper(string &s, int l, int r) {
        // Base case: if left index crosses right, it's a palindrome
        if (l >= r) return true;

        // If current left char is NOT alphanumeric, skip it
        if (!isalnum(s[l])) return helper(s, l + 1, r);

        // If current right char is NOT alphanumeric, skip it
        if (!isalnum(s[r])) return helper(s, l, r - 1);

        // Compare characters (ignoring case)
        if (tolower(s[l]) != tolower(s[r])) 
            return false; // mismatch → not a palindrome

        // Move inward and check the next pair
        return helper(s, l + 1, r - 1);
    }

    bool isPalindrome(string s) {
        // Start recursion from both ends
        return helper(s, 0, s.size() - 1);
    }
};
