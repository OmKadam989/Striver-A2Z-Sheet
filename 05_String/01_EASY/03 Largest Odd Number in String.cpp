// 🔹 Problem: Largest Odd Number in String (LeetCode 1903)
// https://leetcode.com/problems/largest-odd-number-in-string/description/
//
// You are given a string `num` representing a large integer.  
// Return the **largest-valued odd integer (as a string)** that is a **non-empty substring** 
// of `num` and starts from the **beginning** of the string.
//
// If no such odd number exists, return an empty string.
//
// Example 1:
// Input:  num = "35427"
// Output: "35427"   // last digit 7 is odd
//
// Example 2:
// Input:  num = "4206"
// Output: ""         // no odd digit
//
// Example 3:
// Input:  num = "52"
// Output: "5"
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// 1. Start from the full string, remove one digit from the end at a time.
// 2. For each prefix, check if the last digit is odd.
// 3. The first odd-ending prefix you find is the largest odd number.
//
// Time Complexity: O(n²)  [substring creation each time]
// Space Complexity: O(n)
string largestOddNumberBrute(string num) {
    int n = num.size();
    for (int i = n; i >= 1; i--) {
        string sub = num.substr(0, i);
        int last = sub.back() - '0';
        if (last % 2 == 1) return sub;
    }
    return "";
}

// ---------------- Optimal ----------------
// Approach:
// 1. Traverse from right to left.
// 2. The first odd digit from the end indicates the largest odd prefix.
// 3. Return substring from 0 to that index.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
string largestOddNumberOptimal(string num) {
    int n = num.size();
    for (int i = n - 1; i >= 0; i--) {
        int no = num[i] - '0';
        if (no % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

// ---------------- Driver ----------------
int main() {
    vector<string> tests = {
        "35427",
        "4206",
        "52",
        "2224",
        "123456"
    };

    for (const string &num : tests) {
        cout << "Input:  \"" << num << "\"" << endl;
        cout << "[Brute]   -> \"" << largestOddNumberBrute(num) << "\"" << endl;
        cout << "[Optimal] -> \"" << largestOddNumberOptimal(num) << "\"" << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}

/*
Expected Output:
Input:  "35427"
[Brute]   -> "35427"
[Optimal] -> "35427"
------------------------------------
Input:  "4206"
[Brute]   -> ""
[Optimal] -> ""
------------------------------------
Input:  "52"
[Brute]   -> "5"
[Optimal] -> "5"
------------------------------------
Input:  "2224"
[Brute]   -> ""
[Optimal] -> ""
------------------------------------
Input:  "123456"
[Brute]   -> "12345"
[Optimal] -> "12345"
------------------------------------
*/
