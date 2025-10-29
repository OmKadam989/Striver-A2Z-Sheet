// 🔹 Problem: Find a Peak Element II (LeetCode 1901)
// https://leetcode.com/problems/find-a-peak-element-ii/description/
//
// Given a 0-indexed m × n matrix `mat` where no two adjacent cells are equal,
// find *any* peak element `mat[i][j]` and return the pair `[i, j]`.
// A peak element is one strictly greater than all its up/down/left/right neighbors.
// You must design an algorithm with O(m log n) or O(n log m) time complexity.
//
// Example 1:
// Input: mat = [[1, 4],[3, 2]]
// Output: [0,1]   // either [0,1] (value=4) or [1,0] (value=3) is fine.
//
// Example 2:
// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]   // value=30 (or [2,2] value=32) is a peak.
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force (Full Scan) ----------------
// Approach:
// Check every cell in the matrix and see if it's strictly greater than its neighbors.
// Return the first found peak.
//
// Time Complexity: O(m × n)   (since for each cell we check up to 4 neighbors)  
// Space Complexity: O(1)
vector<int> findPeakBrute(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {-1, -1};
    int n = mat[0].size();
    auto isValid = [&](int r, int c) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    };
    // directions: up, down, left, right
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool peak = true;
            for (auto &d : dirs) {
                int nr = i + d.first, nc = j + d.second;
                if (isValid(nr, nc) && mat[nr][nc] >= mat[i][j]) {
                    peak = false;
                    break;
                }
            }
            if (peak) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// ---------------- Optimal Approach (Binary Search on Rows) ----------------
// Idea:
// Use binary search over rows:
//   1. Choose mid row.
//   2. Find the column index `colMax` of its maximum element.
//   3. Compare `mat[mid][colMax]` with the element directly below (if exists).
//      - If `mat[mid][colMax] > mat[mid+1][colMax]`, the peak must lie in row ≤ mid.
//      - Else, peak lies in row ≥ mid + 1.
// Repeat until low == high. Then find the max element in that row and return its indices.
//
// Time Complexity: O(n × log m) or O(m × log n) depending on how we binary search (rows vs columns).  
// Space Complexity: O(1)
vector<int> findPeakOptimal(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {-1, -1};
    int n = mat[0].size();
    int low = 0, high = m - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        // Find column index of maximum element in row mid
        int colMax = 0;
        for (int j = 1; j < n; j++) {
            if (mat[mid][j] > mat[mid][colMax]) {
                colMax = j;
            }
        }
        // Compare with element in next row
        if (mat[mid][colMax] > mat[mid + 1][colMax]) {
            // Peak is in this row or above
            high = mid;
        } else {
            // Peak is below
            low = mid + 1;
        }
    }

    // low == high, find max element in that row
    int row = low;
    int colMax = 0;
    for (int j = 1; j < n; j++) {
        if (mat[row][j] > mat[row][colMax]) {
            colMax = j;
        }
    }
    return {row, colMax};
}

// ---------------- Driver ----------------
int main() {
    vector<vector<int>> mat1 = {{1,4},{3,2}};
    auto p1_brute   = findPeakBrute(mat1);
    auto p1_optimal = findPeakOptimal(mat1);
    cout << "[Brute]   → [" << p1_brute[0] << "," << p1_brute[1] << "]" << endl;
    cout << "[Optimal] → [" << p1_optimal[0] << "," << p1_optimal[1] << "]" << endl;

    vector<vector<int>> mat2 = {
        {10,20,15},
        {21,30,14},
        {7,16,32}
    };
    auto p2_brute   = findPeakBrute(mat2);
    auto p2_optimal = findPeakOptimal(mat2);
    cout << "[Brute]   → [" << p2_brute[0] << "," << p2_brute[1] << "]" << endl;
    cout << "[Optimal] → [" << p2_optimal[0] << "," << p2_optimal[1] << "]" << endl;

    return 0;
}

/*
Expected Output (one possible peak coordinate each):
[Brute]   → [0,1]
[Optimal] → [0,1]
[Brute]   → [1,1]
[Optimal] → [2,2]
*/

