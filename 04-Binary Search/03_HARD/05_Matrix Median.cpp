// 🔹 Problem: Matrix Median
// https://takeuforward.org/plus/dsa/problems/matrix-median  
//
// Given a row-wise sorted matrix of size M×N (each row sorted), find the median of the matrix.
// Note: median = the ⌈(M×N)/2⌉-th smallest element if one-based.
//
// Example:
// Input: matrix = [
//   [1, 3, 5],
//   [2, 6, 9],
//   [3, 6, 9]
// ]
// Output: 5  (since sorted elements = [1,2,3,3,5,6,6,9,9], median is the 5th = 5)
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// 1. Collect all elements into a vector.
// 2. Sort the vector.
// 3. Return the element at index (M×N)/2 (0-based) or at (M×N)/2 (1-based) depending.
//
// Time Complexity: O(M×N log(M×N))
// Space Complexity: O(M×N)
int findMedianBrute(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> all;
    all.reserve(m * n);
    for (auto &row : matrix) {
        for (int x : row) {
            all.push_back(x);
        }
    }
    sort(all.begin(), all.end());
    int total = m * n;
    int midIndex = total / 2;  // for odd total, this gives the median
    return all[midIndex];
}

// ---------------- Optimal (Binary Search on Answer) ----------------
// Approach:
// Since each row is sorted, we can binary search on the **value** range.
// Let low = minimum element in matrix, high = maximum element in matrix.
// For a guess value `mid`, count how many elements are ≤ mid (using binary search in each row).
// If count ≤ (M×N)/2, then median is larger → low = mid + 1.
// Else high = mid.
// After the loop, low will be the median.
//
// Time Complexity: O(M × log N × log(maxValue−minValue))
// Space Complexity: O(1)
int findMedianOptimal(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }
    int desired = (m * n + 1) / 2;

    while (low < high) {
        int mid = low + (high - low) / 2;
        // count how many ≤ mid
        long long count = 0;
        for (int i = 0; i < m; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if (count < desired) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

// ---------------- Driver ----------------
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "[Brute]   Median = " << findMedianBrute(matrix) << endl;
    cout << "[Optimal] Median = " << findMedianOptimal(matrix) << endl;
    return 0;
}

/*
Expected Output:
[Brute]   Median = 5
[Optimal] Median = 5
*/
