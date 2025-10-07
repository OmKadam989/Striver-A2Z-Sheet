// 🔹 Problem: Find Square Root of a Number (TakeUForward)
// https://takeuforward.org/plus/dsa/problems/find-square-root-of-a-number  
//
// Given a positive integer n, find and return its integer square root.
// If n is not a perfect square, return the floor value of sqrt(n).
//
// Example:
// Input: n = 36 → Output: 6
// Input: n = 37 → Output: 6
// Input: n = 1 → Output: 1

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Try all integers x from 1 up to sqrt(n). The largest x such that x*x ≤ n is the answer.
//
// Time Complexity: O(√n)
// Space Complexity: O(1)
long long sqrtBrute(long long n) {
    long long x = 0;
    while ((x + 1) * (x + 1) <= n) {
        x++;
    }
    return x;
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use binary search on the range [0, n] (or [1, n]) to find the maximum x such that x*x ≤ n.
// - Compute mid, check mid*mid ≤ n → move right, else move left.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
long long sqrtOptimal(long long n) {
    long long lo = 0, hi = n;
    long long ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        // Use mid*mid may overflow, so careful with type
        if (mid <= n / mid) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

// ---------------- Driver ----------------
int main() {
    vector<long long> tests = {1, 2, 4, 15, 16, 17, 1000000000000LL};
    for (long long n : tests) {
        cout << "n = " << n << " → ";
        cout << "[Brute] " << sqrtBrute(n) << ", ";
        cout << "[Optimal] " << sqrtOptimal(n) << endl;
    }
    return 0;
}

/*
Expected Output:
n = 1 → [Brute] 1, [Optimal] 1
n = 2 → [Brute] 1, [Optimal] 1
n = 4 → [Brute] 2, [Optimal] 2
n = 15 → [Brute] 3, [Optimal] 3
n = 16 → [Brute] 4, [Optimal] 4
n = 17 → [Brute] 4, [Optimal] 4
n = 1000000000000 → [Brute] 1000000, [Optimal] 1000000
*/
