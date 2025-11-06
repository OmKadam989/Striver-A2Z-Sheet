// 🔹 Problem: Longest Common Prefix (LeetCode 14)
// https://leetcode.com/problems/longest-common-prefix/description/
//
// Write a function to find the longest common prefix string amongst an array of
// strings. If there is no common prefix, return an empty string.
//
// Example 1:
// Input: strs = ["flower", "flow", "flight"]
// Output: "fl"
//
// Example 2:
// Input: strs = ["dog", "racecar", "car"]
// Output: ""
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// 1. If the array is empty, return "".
// 2. Use the first string as a candidate prefix.
// 3. For each character position i in the candidate prefix,
//    check all other strings whether they have the same character at i.
// 4. As soon as a mismatch or a string is too short, return the prefix up to i.
// Time Complexity: O(n × m) where n = number of strings, m = length of shortest string.
// Space Complexity: O(1) additional space (excluding output).
string longestCommonPrefixBrute(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    int n = strs.size();
    for (int i = 0; i < prefix.size(); i++) {
        char c = prefix[i];
        for (int j = 1; j < n; j++) {
            if (i == strs[j].size() || strs[j][i] != c) {
                return prefix.substr(0, i);
            }
        }
    }
    return prefix;
}

// ---------------- Better Approach (Divide & Conquer or Horizontal Scan) ----------------
// Here we use horizontal scanning: start with prefix = strs[0], and reduce it
// while comparing with each subsequent string.
// Time Complexity: O(n × m) worst-case.
// Space Complexity: O(1) additional space.
string longestCommonPrefixBetter(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) return "";
    }
    return prefix;
}

// ---------------- Driver ----------------
int main() {
    vector<vector<string>> tests = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"interspecies", "interstellar", "interstate"},
        {"", "prefix", "pre"},
        {"single"}
    };

    for (auto &strs : tests) {
        cout << "Input: [ ";
        for (auto &s : strs) cout << "\"" << s << "\" ";
        cout << "]" << endl;
        cout << "[Brute]  -> \"" << longestCommonPrefixBrute(strs)  << "\"" << endl;
        cout << "[Better] -> \"" << longestCommonPrefixBetter(strs) << "\"" << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}

/*
Expected Output:
Input: [ "flower" "flow" "flight" ]
[Brute]  -> "fl"
[Better] -> "fl"
------------------------------------
Input: [ "dog" "racecar" "car" ]
[Brute]  -> ""
[Better] -> ""
------------------------------------
Input: [ "interspecies" "interstellar" "interstate" ]
[Brute]  -> "inters"
[Better] -> "inters"
------------------------------------
Input: [ "" "prefix" "pre" ]
[Brute]  -> ""
[Better] -> ""
------------------------------------
Input: [ "single" ]
[Brute]  -> "single"
[Better] -> "single"
------------------------------------
*/

