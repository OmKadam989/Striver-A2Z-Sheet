// 🔹 Problem: Remove Outermost Parentheses (LeetCode 1021)  
// https://leetcode.com/problems/remove-outermost-parentheses/description/  
//
// You are given a valid parentheses string `s`. A **primitive** parentheses string is defined as a non-empty valid string that cannot be split into two non-empty valid parentheses strings.  
// The given string `s` can be decomposed into primitive parts:  
//     s = P₁ + P₂ + … + Pₖ  (each Pᵢ is primitive)  
// You must **remove** the outermost parentheses of each primitive part, then concatenate and return the result.
//
// Example:  
// Input:  s = "(()())(())"  
// Output: "()()()"  
// Explanation: primitives → "(()())" + "(())", remove outermost → "()()" + "()" = "()()()"  
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Simple / “Brute-like” Approach ----------------
// Approach:
// Use a stack or manual count to identify primitive boundaries: when the balance counter returns to 0, a primitive ends.
// For each primitive, skip its first '(' and its last ')' then append the rest.
//
// Time Complexity: O(n)  (one pass)  
// Space Complexity: O(n)  (for output string)
string removeOuterBrute(const string &s) {
    string result;
    int balance = 0;
    int start = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance == 0) {
            // Primitive from s[start..i]
            // Append from start+1 to i-1 (skipping outer '(' and ')')
            if (i - start >= 2) {
                result.append(s.substr(start + 1, i - start - 1));
            }
            start = i + 1;
        }
    }
    return result;
}

// ---------------- Optimal Counter Approach ----------------
// Approach:
// Keep a depth counter.  
// For each '(' → increment depth. If after increment depth > 1 → append '(' to result.  
// For each ')' → decrement depth. If after decrement depth > 0 → append ')' to result.
// This automatically skips the outermost '(' (when depth becomes 1) and the outermost ')' (when depth becomes 0).
//
// Time Complexity: O(n)  
// Space Complexity: O(n)
string removeOuterOptimal(const string &s) {
    string result;
    result.reserve(s.size());
    int depth = 0;
    for (char c : s) {
        if (c == '(') {
            depth++;
            if (depth > 1) result.push_back(c);
        } else { // c == ')'
            depth--;
            if (depth > 0) result.push_back(c);
        }
    }
    return result;
}

// ---------------- Driver ----------------
int main() {
    vector<string> tests = {
        "(()())(())",
        "(()())(())(()(()))",
        "()()"
    };

    for (const string &s : tests) {
        cout << "Input: "  << s << endl;
        cout << "[Brute]   -> " << removeOuterBrute(s)   << endl;
        cout << "[Optimal] -> " << removeOuterOptimal(s) << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}

/*
Expected Output:
Input: (()())(())
[Brute]   -> ()()()
[Optimal] -> ()()()
-----------------------------
Input: (()())(())(()(()))
[Brute]   -> ()()()()(())
[Optimal] -> ()()()()(())
-----------------------------
Input: ()()
[Brute]   -> 
[Optimal] -> 
-----------------------------
*/

