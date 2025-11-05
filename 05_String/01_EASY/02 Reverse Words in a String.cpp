// 🔹 Problem: Reverse Words in a String (LeetCode 151)
// https://leetcode.com/problems/reverse-words-in-a-string/description/
//
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters.
// The words in s will be separated by **one or more** spaces.
// Return a string of the words in reverse order, **concatenated by a single space**.
//
// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"
//
// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
//
// Note: The returned string should not contain leading or trailing spaces,
// and words should be separated by exactly one space.
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// 1. Extract all words by scanning the string: skip spaces, then read the next word.
// 2. Store words in a vector.
// 3. Reverse the vector of words.
// 4. Join them using a single space separator.
// Time Complexity: O(n) for scanning + O(n) for join = O(n)
// Space Complexity: O(n) for storing words and the result.
string reverseWordsBrute(const string &s) {
    vector<string> words;
    int i = 0, n = s.size();
    while (i < n) {
        // skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i >= n) break;
        int j = i;
        while (j < n && s[j] != ' ') {
            j++;
        }
        words.push_back(s.substr(i, j - i));
        i = j;
    }
    reverse(words.begin(), words.end());
    string result;
    for (int k = 0; k < words.size(); k++) {
        if (k > 0) result += ' ';
        result += words[k];
    }
    return result;
}

// ---------------- Optimal In-Place Style ----------------
// Approach:
// 1. Reverse the entire string.
// 2. Then reverse each word in place and also collapse spaces:
//    - While scanning the reversed string, copy characters of each word
//      and reverse them when complete.
//    - Skip and collapse multiple spaces into one.
// 3. Trim trailing space if any.
// Time Complexity: O(n)
// Space Complexity: O(n) (for result construction) or O(1) additional if done fully in-place.
string reverseWordsOptimal(string s) {
    int n = s.size();
    // reverse whole string
    reverse(s.begin(), s.end());
    string result;
    result.reserve(n);
    int i = 0;
    while (i < n) {
        // skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i >= n) break;

        if (!result.empty()) {
            result.push_back(' ');
        }

        int start = i;
        while (i < n && s[i] != ' ') {
            result.push_back(s[i]);
            i++;
        }
        int end = result.size();
        // reverse the word just added
        reverse(result.begin() + (end - (i - start)), result.begin() + end);
    }
    return result;
}

// ---------------- Driver ----------------
int main() {
    vector<string> tests = {
        "the sky is blue",
        "  hello   world  ",
        "a good   example"
    };

    for (const string &s : tests) {
        cout << "Input:  \"" << s << "\"" << endl;
        cout << "[Brute]   -> \"" << reverseWordsBrute(s) << "\"" << endl;
        cout << "[Optimal] -> \"" << reverseWordsOptimal(s) << "\"" << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}

/*
Expected Output:
Input:  "the sky is blue"
[Brute]   -> "blue is sky the"
[Optimal] -> "blue is sky the"
------------------------------------
Input:  "  hello   world  "
[Brute]   -> "world hello"
[Optimal] -> "world hello"
------------------------------------
Input:  "a good   example"
[Brute]   -> "example good a"
[Optimal] -> "example good a"
------------------------------------
*/
