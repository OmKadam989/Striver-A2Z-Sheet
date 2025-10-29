// 🔹 Problem: Search a 2D Matrix II (LeetCode 240)
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
//
// Given an m × n matrix where each row is sorted in ascending order
// from left to right, and each column is sorted in ascending order
// from top to bottom. Given a target value, return true if the target
// exists in the matrix, otherwise return false.
//
// Example 1:
// Input: matrix = [
//   [1,  4,  7, 11, 15],
//   [2,  5,  8, 12, 19],
//   [3,  6,  9, 16, 22],
//   [10,13,14,17,24],
//   [18,21,23,26,30]
// ], target = 5
// Output: true
//
// Example 2:
// Input: same matrix, target = 20
// Output: false
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Traverse every element in the matrix and compare with target.
//
// Time Complexity: O(m × n)
// Space Complexity: O(1)
bool searchMatrixBrute(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// ---------------- Optimal (Staircase Search) ----------------
// Approach:
// Start from the top-right corner (row = 0, col = n-1).  
// At each position:
//   - If current element == target → return true.
//   - If current element > target → move left (col--), because all elements below in that column will be even larger.
//   - If current element < target → move down (row++), because all elements to the left in that row are smaller.
// This way we eliminate either a row or a column at each step.
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)
bool searchMatrixOptimal(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        int val = matrix[row][col];
        if (val == target) {
            return true;
        } else if (val > target) {
            col--;
        } else {
            row++;
        }
    }

    return false;
}

// ---------------- Driver ----------------
int main() {
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target1 = 5;
    int target2 = 20;

    cout << "[Brute]   → " << (searchMatrixBrute(matrix, target1)    ? "true" : "false") << endl;
    cout << "[Optimal] → " << (searchMatrixOptimal(matrix, target1) ? "true" : "false") << endl;

    cout << "[Brute]   → " << (searchMatrixBrute(matrix, target2)    ? "true" : "false") << endl;
    cout << "[Optimal] → " << (searchMatrixOptimal(matrix, target2) ? "true" : "false") << endl;

    return 0;
}

/*
Expected Output:
[Brute]   → true
[Optimal] → true
[Brute]   → false
[Optimal] → false
*/
