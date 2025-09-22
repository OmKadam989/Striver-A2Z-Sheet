// 🔹 Problem: Pascal's Triangle Variations
// -------------------------------------------------
// This program demonstrates different approaches:
// 1. Compute nCr (Binomial Coefficient) using iterative formula
// 2. Generate the entire Pascal’s Triangle
// 3. Generate a specific row of Pascal’s Triangle
//
// Author: Om Kadam
// -------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// ✅ Function 1: Compute nCr (Binomial Coefficient)
// Formula: nCr = n! / (r! * (n-r)!)
// Optimized iterative way to avoid overflow
// -------------------------------------------------
int nCr(int n, int r) {
    long long ans = 1;
    for (int i = 0; i < r; i++) {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return (int)ans;
}

// -------------------------------------------------
// ✅ Function 2: Generate a single row of Pascal's Triangle
// Row indexing starts from 1
// Example: row = 5 → [1, 4, 6, 4, 1]
// -------------------------------------------------
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);

    for (int i = 1; i < row; i++) {
        ans = ans * (row - i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// -------------------------------------------------
// ✅ Function 3: Generate Pascal's Triangle up to numRows
// -------------------------------------------------
vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> triangle;
    for (int i = 1; i <= numRows; i++) {
        triangle.push_back(generateRow(i));
    }
    return triangle;
}

// -------------------------------------------------
// ✅ Function 4: Get nth Row of Pascal's Triangle
// Direct computation without building full triangle
// -------------------------------------------------
vector<int> nthRowOfPascalTriangle(int n) {
    vector<int> ansRow;
    long long ans = 1;
    ansRow.push_back(ans);

    for (int col = 1; col < n; col++) {
        ans = ans * (n - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// -------------------------------------------------
// 🚀 Driver Code
// -------------------------------------------------
int main() {
    // Example 1: Compute nCr
    int n = 4, r = 2;
    cout << "nCr (" << n << "C" << r << ") = " << nCr(n, r) << endl;

    // Example 2: Generate full Pascal’s Triangle
    int numRows = 5;
    cout << "\nPascal's Triangle up to " << numRows << " rows:\n";
    vector<vector<int>> triangle = generatePascal(numRows);
    for (auto row : triangle) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }

    // Example 3: Get nth Row of Pascal’s Triangle
    int rowNum = 5;
    cout << "\n" << rowNum << "th Row of Pascal’s Triangle:\n";
    vector<int> nthRow = nthRowOfPascalTriangle(rowNum);
    for (auto val : nthRow) cout << val << " ";
    cout << endl;

    return 0;
}
