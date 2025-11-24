// 🔹 Problem: Find Row with Maximum Number of 1’s
// https://www.geeksforgeeks.org/dsa/find-the-row-with-maximum-number-of-1s/ :contentReference[oaicite:2]{index=2}
// Given a binary matrix of size m × n, where each row is sorted (0s followed by 1s).
// Find the index of the row that contains the maximum number of 1’s.
// If multiple rows have the same count of 1s, return the smallest index.
// Return the pair: {rowIndex, countOfOnes}.
//
// Example:
// Input:
//   mat = [
//     [0, 1, 1, 1],
//     [0, 0, 1, 1],
//     [1, 1, 1, 1],
//     [0, 0, 0, 0]
//   ]
// Output: {2, 4}  // Row-2 has 4 ones, maximum among all.
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// For each row, iterate through all columns and count the number of 1’s.
// Track the max count and its row index.
//
// Time Complexity: O(m × n)
// Space Complexity: O(1)
pair<int,int> rowWithMaxOnesBrute(const vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {-1, 0};
    int n = mat[0].size();

    int maxCount = 0;
    int bestRow = -1;

    for (int i = 0; i < m; i++) {
        int count1s = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) count1s++;
        }
        if (count1s > maxCount) {
            maxCount = count1s;
            bestRow = i;
        }
    }

    return {bestRow, maxCount};
}

// ---------------- Better Approach (Binary Search per Row) ----------------
// Approach:
// Because each row is sorted, we can binary-search for the first occurrence of 1 in each row.
// Then number of 1’s in that row = (n − index_of_first_1).
// For each row, compute this, track max count & smallest row index for ties.
//
// Time Complexity: O(m × log n)
// Space Complexity: O(1)
pair<int,int> rowWithMaxOnesBinary(const vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {-1, 0};
    int n = mat[0].size();

    int maxCount = 0;
    int bestRow = -1;

    for (int i = 0; i < m; i++) {
        int lo = 0, hi = n - 1, firstOne = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mat[i][mid] == 1) {
                firstOne = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int count1s = (firstOne == n ? 0 : (n - firstOne));
        if (count1s > maxCount) {
            maxCount = count1s;
            bestRow = i;
        }
    }

    return {bestRow, maxCount};
}

// ---------------- Optimal Approach (O(m + n)) ----------------
// Approach:
// Use a pointer starting at the top-right corner (row = 0, col = n-1).
// Move left while you see 1’s, update best row. When you hit 0 or run of 1’s ends,
// move down to next row and continue from current column.
// You traverse at most m + n steps.
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)
pair<int,int> rowWithMaxOnesOptimal(const vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {-1, 0};
    int n = mat[0].size();

    int bestRow = -1, maxCount = 0;
    int j = n - 1;

    for (int i = 0; i < m; i++) {
        while (j >= 0 && mat[i][j] == 1) {
            j--;
        }
        // number of ones in this row = (n - 1 - j)
        int count1s = n - 1 - j;
        if (count1s > maxCount) {
            maxCount = count1s;
            bestRow = i;
        }
    }
    return {bestRow, maxCount};
}

// ---------------- Driver ----------------
int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    auto bruteAns  = rowWithMaxOnesBrute(mat);
    auto binaryAns = rowWithMaxOnesBinary(mat);
    auto optimalAns= rowWithMaxOnesOptimal(mat);

    cout << "[Brute]   → Row: " << bruteAns.first  << ", Count: " << bruteAns.second  << endl;
    cout << "[Binary]  → Row: " << binaryAns.first << ", Count: " << binaryAns.second << endl;
    cout << "[Optimal] → Row: " << optimalAns.first<< ", Count: " << optimalAns.second << endl;

    return 0;
}

/*
Expected Output:
[Brute]   → Row: 2, Count: 4
[Binary]  → Row: 2, Count: 4
[Optimal] → Row: 2, Count: 4
*/
