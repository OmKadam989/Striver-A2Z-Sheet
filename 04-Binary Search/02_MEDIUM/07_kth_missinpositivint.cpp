// 🔹 Problem: K-th Missing Positive Number (LeetCode 1539)
// https://leetcode.com/problems/kth-missing-positive-number/description/
//
// You are given a **strictly increasing** array `arr` and an integer `k`.  
// You must return the k-th positive integer that is missing from this array.
//
// Example:
// Input: arr = [2,3,4,7,11], k = 5  
// Missing positives: [1,5,6,8,9,10,12,...]  
// The 5th missing is 9 → return 9  
//
// Input: arr = [1,2,3,4], k = 2  
// Missing positives: [5,6,7,...]  
// The 2nd missing is 6 → return 6

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Start from 1 and iterate positive integers. Use a pointer over `arr` to check if a number is in arr or not.
// Maintain a count of missing numbers until it reaches k, then return that integer.
//
// Time Complexity: O(n + k)  
// Space Complexity: O(1)
int findKthPositiveBrute(vector<int>& arr, int k) {
    int missingCount = 0;
    int cur = 1;
    int i = 0;
    int n = arr.size();

    while (true) {
        if (i < n && arr[i] == cur) {
            // this number is in arr, skip
            i++;
        } else {
            // this number is missing
            missingCount++;
            if (missingCount == k) {
                return cur;
            }
        }
        cur++;
    }
    // never reach here
    return -1;
}

// ---------------- Optimal (Binary Search + Offset Insight) ----------------
// Key Observation:
// For index `i`, number of missing integers before arr[i] is:
//    missingBefore = arr[i] - (i + 1)
//
// If missingBefore < k, then the k-th missing is to the right of i.
// If missingBefore >= k, it's at or to the left of i.
//
// Use binary search on index to find the smallest index `i` such that missingBefore >= k.
// Then the answer is: (i) + k  (i.e. k more than i elements covered).
//
// Time Complexity: O(log n)  
// Space Complexity: O(1)
int findKthPositiveOptimal(vector<int>& arr, int k) {
    int n = arr.size();

    // if the total missing before the last element is still less than k,
    // it means the k-th missing lies after the array end
    int missingBeforeLast = arr[n-1] - n;
    if (missingBeforeLast < k) {
        // it's beyond the last element
        return arr[n-1] + (k - missingBeforeLast);
    }

    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int missingBeforeMid = arr[mid] - (mid + 1);
        if (missingBeforeMid < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    // lo (or hi) is the first index where missingBefore >= k
    // The k-th missing is before arr[lo], so compute:
    return lo + k;
}

// ---------------- Driver ----------------
int main() {
    vector<int> arr1 = {2,3,4,7,11};
    int k1 = 5;

    cout << "[Brute]  -> " << findKthPositiveBrute(arr1, k1) << endl;
    cout << "[Optimal] -> " << findKthPositiveOptimal(arr1, k1) << endl;

    vector<int> arr2 = {1,2,3,4};
    int k2 = 2;

    cout << "[Brute]  -> " << findKthPositiveBrute(arr2, k2) << endl;
    cout << "[Optimal] -> " << findKthPositiveOptimal(arr2, k2) << endl;

    return 0;
}

/*
Expected Output:
[Brute]  -> 9
[Optimal] -> 9
[Brute]  -> 6
[Optimal] -> 6
*/
