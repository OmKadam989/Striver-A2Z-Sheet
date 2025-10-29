// 🔹 Problem: Search a 2D Matrix (LeetCode 74)
// https://leetcode.com/problems/search-a-2d-matrix/description/
//
// You are given an m × n integer matrix `matrix` with the following properties:
// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater than the last integer of the previous row.
//
// Given a target value, return true if the target exists in the matrix, otherwise false.
//
// Example:
// Input: matrix = [[1,3,5,7],
//                  [10,11,16,20],
//                  [23,30,34,60]], target = 3
// Output: true
//
// Example:
// Input: matrix = [[1,3,5,7],
//                  [10,11,16,20],
//                  [23,30,34,60]], target = 13
// Output: false
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Traverse every element of the matrix and check if it equals target.
//
// Time Complexity: O(m × n)
// Space Complexity: O(1)
bool searchMatrixBrute(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}

// ---------------- Optimal (Flattened Binary Search) ----------------
// Approach:
// Because the matrix is like one sorted array (row-by-row) due to the given properties,
// we can treat it as a 1D sorted array of length m * n and apply binary search.
// Map mid index to 2D: row = mid / n, col = mid % n.
//
// Time Complexity: O(log(m * n))
// Space Complexity: O(1)
bool searchMatrixOptimal(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int lo = 0, hi = m * n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int row = mid / n;
        int col = mid % n;
        int val = matrix[row][col];

        if (val == target) {
            return true;
        } else if (val < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}

// ---------------- Driver ----------------
int main() {
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target1 = 3;

    cout << "[Brute]   → " << (searchMatrixBrute(matrix1, target1)    ? "true" : "false") << endl;
    cout << "[Optimal] → " << (searchMatrixOptimal(matrix1, target1) ? "true" : "false") << endl;

    int target2 = 13;
    cout << "[Brute]   → " << (searchMatrixBrute(matrix1, target2)    ? "true" : "false") << endl;
    cout << "[Optimal] → " << (searchMatrixOptimal(matrix1, target2) ? "true" : "false") << endl;

    return 0;
}

/*
Expected Output:
[Brute]   → true
[Optimal] → true
[Brute]   → false
[Optimal] → false
*/
