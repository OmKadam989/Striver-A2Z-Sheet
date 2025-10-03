// 🔹 Problem: Count Occurrences in Sorted Array
// https://takeuforward.org/data-structure/count-occurrences-in-sorted-array/ :contentReference[oaicite:0]{index=0}
//
// You are given a sorted array and a target value x.
// You need to count how many times x appears in the array.
// Return that count.
//
// Example:
// Input:  nums = [1,2,2,2,3,4,5], x = 2
// Output: 3
//
// Approaches:
// 1. Brute Force → scan entire array (O(n))
// 2. Optimal → use binary search to find first and last occurrence (O(log n))

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force Approach ----------------
// Idea:
// Traverse the entire array. Each time arr[i] == x, increment count.
// Time Complexity: O(n)
// Space Complexity: O(1)
int countOccurrencesBrute(const vector<int>& arr, int x) {
    int count = 0;
    for (int v : arr) {
        if (v == x) count++;
    }
    return count;
}

// ---------------- Optimal Approach (Binary Search) ----------------
// Idea:
// Use two binary searches to find:
//   - first index where arr[first] == x
//   - last index where arr[last] == x
// Then count = last - first + 1.
// If x isn't found at all, return 0.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
int firstOccurrence(const vector<int>& arr, int x) {
    int lo = 0, hi = arr.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x) {
            ans = mid;
            hi = mid - 1;  // search left half for earlier occurrence
        }
        else if (arr[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

int lastOccurrence(const vector<int>& arr, int x) {
    int lo = 0, hi = arr.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x) {
            ans = mid;
            lo = mid + 1;  // search right half for later occurrence
        }
        else if (arr[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

int countOccurrencesOptimal(const vector<int>& arr, int x) {
    int first = firstOccurrence(arr, x);
    if (first == -1) return 0;  // x is not present
    int last = lastOccurrence(arr, x);
    return last - first + 1;
}

// ---------------- Driver ----------------
int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    cout << "[Brute Force] Count = " << countOccurrencesBrute(nums, x) << endl;
    cout << "[Optimal] Count = " << countOccurrencesOptimal(nums, x) << endl;

    return 0;
}

/*
Expected Output:
[Brute Force] Count = 3
[Optimal] Count = 3
*/
