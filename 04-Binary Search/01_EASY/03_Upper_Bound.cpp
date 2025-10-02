// Upper Bound Problem
// Given a sorted array and a value x, find the smallest index i such that arr[i] > x.
// If no such index exists, return n.
//
// Example:
// Input: arr = [1, 2, 4, 4, 5, 7], x = 4
// Output: 4   (since arr[4] = 5 is the first element > 4)
//
// Approaches:
// 1. Brute Force: O(n), linear scan
// 2. Optimal: O(log n), binary search

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Scan the array from left to right.
// The first element greater than x is our answer.
// If none exists, return n.
// Time Complexity: O(n)
int upperBoundBrute(const vector<int>& arr, int x) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) return i;
    }
    return n; // if no element is greater
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use binary search to find the first element > x.
// - If arr[mid] > x → candidate answer, move left (high = mid - 1).
// - Else arr[mid] <= x → move right (low = mid + 1).
// Finally, 'ans' holds the smallest index with arr[ans] > x, or n if none.
// Time Complexity: O(log n)
int upperBoundOptimal(const vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1, ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;       // possible answer
            high = mid - 1;  // search left
        } else {
            low = mid + 1;   // search right
        }
    }
    return ans;
}

// ---------------- Driver ----------------
int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int x = 4;

    cout << "[Brute Force] Upper bound index: " << upperBoundBrute(arr, x) << endl;
    cout << "[Optimal] Upper bound index: " << upperBoundOptimal(arr, x) << endl;

    return 0;
}

/*
Expected Output:
[Brute Force] Upper bound index: 4
[Optimal] Upper bound index: 4
*/
