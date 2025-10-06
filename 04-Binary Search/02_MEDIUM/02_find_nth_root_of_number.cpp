// 🔹 Problem: Find nth Root of M (GFG)
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
//
// You are given two positive integers n and m.  
// You need to find the integer nth root of m.  
// If the nth root is not an integer, return -1.
//
// Example:
// Input: n = 2, m = 9  
// Output: 3   (because 3^2 = 9)
//
// Input: n = 3, m = 27  
// Output: 3   (because 3^3 = 27)
//
// Input: n = 2, m = 16  
// Output: 4
//
// Input: n = 2, m = 17  
// Output: -1  (since √17 is not an integer)

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force Approach ----------------
// Approach:
// Try all integers x from 1 up to pow(m, 1/n) (or up to m).
// Check if x^n == m. If yes, return x. Otherwise return -1.
//
// Time Complexity: O(m^(1/n) * n) roughly → too slow if m is large.
// Space Complexity: O(1)
int nthRootBrute(int n, int m) {
    for (int x = 1; (long long) x * x <= m; x++) {
        // Check power
        long long powVal = 1;
        for (int i = 0; i < n; i++) {
            powVal = powVal * x;
            if (powVal > m) break;
        }
        if (powVal == m) return x;
    }
    return -1;
}

// ---------------- Optimal Approach (Binary Search) ----------------
// Approach:
// Use binary search to find x in range [1, m].  
// For mid, compute mid^n carefully (watch overflow) and compare with m.
// If mid^n == m → answer.  
// If mid^n < m → go right.  
// If mid^n > m → go left.
//
// Time Complexity: O(log m * n)  
// Space Complexity: O(1)
int nthRootOptimal(int n, int m) {
    int lo = 1, hi = m;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // Compute mid^n but break if it exceeds m
        long long powVal = 1;
        for (int i = 0; i < n; i++) {
            powVal = powVal * mid;
            if (powVal > m) break;
        }

        if (powVal == m) {
            return mid;
        }
        else if (powVal < m) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

// ---------------- Driver Code ----------------
int main() {
    vector<pair<int,int>> tests = {
        {2, 9},
        {3, 27},
        {2, 16},
        {2, 17},
        {5, 32},  // 2^5 = 32 => should return 2
        {3, 28}   // no integer cube root => -1
    };
    for (auto &p : tests) {
        int n = p.first, m = p.second;
        cout << "n = " << n << ", m = " << m << " => ";
        cout << "[Brute] " << nthRootBrute(n, m)
             << ", [Optimal] " << nthRootOptimal(n, m) << endl;
    }
    return 0;
}

/*
Expected Output:
n = 2, m = 9 => [Brute] 3, [Optimal] 3
n = 3, m = 27 => [Brute] 3, [Optimal] 3
n = 2, m = 16 => [Brute] 4, [Optimal] 4
n = 2, m = 17 => [Brute] -1, [Optimal] -1
n = 5, m = 32 => [Brute] 2, [Optimal] 2
n = 3, m = 28 => [Brute] -1, [Optimal] -1
*/
