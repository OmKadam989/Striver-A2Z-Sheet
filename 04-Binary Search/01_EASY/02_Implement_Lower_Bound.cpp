// Lower Bound Problem
// Given a sorted array and a value x, find the smallest index i such that arr[i] >= x.
// If no such index exists, return n.
//
// Example:
// Input: arr = [1, 2, 4, 7, 9], x = 4
// Output: 2   (since arr[2] = 4 is the first >= 4)
//
// Input: arr = [1, 2, 4, 7, 9], x = 5
// Output: 3   (since arr[3] = 7 is the first >= 5)
//
// Approaches:
// 1. Brute Force: O(n), linear scan
// 2. Optimal: O(log n), binary search

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Simply scan the array from left to right.
// The first element >= x is our answer.
// If no such element exists, return n.
// Time Complexity: O(n)
int lower_bound_brute(const vector<int>& arr, int x) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) return i;
    }
    return n; // not found
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use binary search to reduce the search space.
// Keep shrinking [lo..hi) until lo == hi.
// - If arr[mid] < x → move right (lo = mid+1).
// - Else → possible answer, so move left (hi = mid).
// Finally, lo is the first index with arr[lo] >= x,
// or n if all elements are smaller.
// Time Complexity: O(log n)
int lower_bound_optimal(const vector<int>& arr, int x) {
    int n = arr.size();
    int lo = 0, hi = n;  // hi = n means "not found" case

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < x) {
            lo = mid + 1; // search right half
        } else {
            hi = mid;     // possible answer, search left half
        }
    }
    // lo == hi is the first index where arr[lo] >= x, or n if none
    return lo;
}

// ---------------- Driver ----------------
int main() {
    vector<int> arr = {1, 2, 4, 7, 9};
    int x = 5;

    cout << "[Brute Force] Index: " << lower_bound_brute(arr, x) << endl;
    cout << "[Optimal] Index: " << lower_bound_optimal(arr, x) << endl;

    return 0;
}
