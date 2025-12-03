// 🔹 Problem: Sum of Beauty of All Substrings (LeetCode 1781)
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
//
// A substring's **beauty** is defined as:
//      (frequency of the most frequent character) 
//    - (frequency of the least frequent character, excluding zero)
//
// You must compute the SUM of beauty values of **all substrings** of the string `s`.
//
// Example:
// Input:  s = "aabcb"
// Substrings and beauties:
//   "a" → 1-1 = 0
//   "aa" → 2-0 = 2
//   "aab" → 2-1 = 1
//   ...
// Total beauty = 5
//
// -------------------------------------------------------------
// ✔️ Approach (Brute-force with Frequency Tracking)
// -------------------------------------------------------------
// For every starting index i:
//     Maintain a frequency array of size 26.
//     For each ending index j ≥ i:
//         Update frequency of s[j].
//         Compute max frequency and min non-zero frequency.
//         Add (max - min) to answer.
//
// Time Complexity: O(n² * 26)  → acceptable for n ≤ 500
// Space Complexity: O(26) per iteration
//
// -------------------------------------------------------------
// Below is the FULL solution with helper functions.
//

class Solution {
    // Return maximum frequency among characters
    int getMaxCount(vector<int> freq) {
        int maxcount = 0;
        for (auto count : freq) {
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }

    // Return minimum NON-ZERO frequency among characters
    int getMinCount(vector<int> &freq) {
        int mincount = INT_MAX;
        for (auto count : freq) {
            if (count != 0)
                mincount = min(count, mincount);
        }
        return mincount;
    }

public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // fresh freq for each i

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;  // update frequency of current char

                int beauty = getMaxCount(freq) - getMinCount(freq);
                sum += beauty;
            }
        }

        return sum;
    }
};
