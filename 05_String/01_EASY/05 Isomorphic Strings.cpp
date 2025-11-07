// 🔹 Problem: Isomorphic Strings (LeetCode 205)
// https://leetcode.com/problems/isomorphic-strings/description/
//
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order.
// No two characters may map to the same character, but a character may map to itself.
//
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
//
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
// Input: s = "paper", t = "title"
// Output: true
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// For every character in s and t at each position i:
//   • If mapping of s[i] → t[i] is not yet established, check that t[i] is not already mapped from another char.
//   • If mapping is already established, verify it matches t[i].
// Time Complexity: O(n * C) in worst case (with checks) ~ O(n²) for naive unique-mapping checking.
// Space Complexity: O(n) for storing mappings.
bool isIsomorphicBrute(const string &s, const string &t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c1 = s[i], c2 = t[i];
        // if mapping exists, check consistency
        if (mapST.count(c1) && mapST[c1] != c2) return false;
        if (mapTS.count(c2) && mapTS[c2] != c1) return false;
        // otherwise establish mapping
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }
    return true;
}

// ---------------- Optimized Approach (Two-Fixed Arrays) ----------------
// Approach:
// Since s and t consist of ASCII characters, we can use two fixed-size arrays to track last seen positions.
// For index i, check if last_seen_s[s[i]] == last_seen_t[t[i]]; if not, return false.
// Then update them to i+1 (to avoid initial zero confusion).
// Time Complexity: O(n)
// Space Complexity: O(C) where C is constant (256 for ASCII) → O(1)
bool isIsomorphicOptimized(const string &s, const string &t) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    vector<int> lastSeenS(256, 0), lastSeenT(256, 0);
    for (int i = 0; i < n; i++) {
        char c1 = s[i], c2 = t[i];
        if (lastSeenS[c1] != lastSeenT[c2]) return false;
        lastSeenS[c1] = i + 1;
        lastSeenT[c2] = i + 1;
    }
    return true;
}

// ---------------- Driver ----------------
int main() {
    vector<pair<string,string>> tests = {
        {"egg", "add"},
        {"foo", "bar"},
        {"paper", "title"},
        {"ab", "aa"},
        {"aa", "ab"}
    };

    for (auto &p : tests) {
        cout << "Input: s = \"" << p.first << "\", t = \"" << p.second << "\"" << endl;
        cout << "[Brute]     -> " << (isIsomorphicBrute(p.first, p.second)     ? "true" : "false") << endl;
        cout << "[Optimized] -> " << (isIsomorphicOptimized(p.first, p.second) ? "true" : "false") << endl;
        cout << "------------------------------------" << endl;
    }
    return 0;
}

/*
Expected Output:
Input: s = "egg", t = "add"
[Brute]     -> true
[Optimized] -> true
------------------------------------
Input: s = "foo", t = "bar"
[Brute]     -> false
[Optimized] -> false
------------------------------------
Input: s = "paper", t = "title"
[Brute]     -> true
[Optimized] -> true
------------------------------------
Input: s = "ab", t = "aa"
[Brute]     -> false
[Optimized] -> false
------------------------------------
Input: s = "aa", t = "ab"
[Brute]     -> false
[Optimized] -> false
------------------------------------
*/

