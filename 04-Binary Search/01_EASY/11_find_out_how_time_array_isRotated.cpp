// 🔹 Problem: Find How Many Times the Array Has Been Rotated
// https://takeuforward.org/plus/dsa/problems/find-out-how-many-times-the-array-is-rotated  
//
// Given a sorted array that has been rotated, find how many times it was rotated.
// Rotation count = index of the minimum element in the rotated array.
// e.g. arr = [3,4,5,1,2] → rotated 3 times (minimum 1 is at index 3)

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Just scan the array to find the minimum element and its index.
// That index is the number of rotations (for a strictly increasing original array).
//
// Time Complexity: O(n)  
// Space Complexity: O(1)
int rotationCountBrute(const vector<int>& arr) {
    int n = arr.size();
    int minVal = arr[0];
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIdx = i;
        }
    }
    return minIdx;
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use a variant of binary search to find the pivot (minimum element).
// While lo < hi:
//   mid = lo + (hi - lo)/2
//   If arr[mid] > arr[hi] → minimum is to the right → lo = mid + 1
//   Else → minimum is at mid or to the left → hi = mid
// After loop, lo == hi is index of smallest element → rotation count.
//
// Time Complexity: O(log n)  
// Space Complexity: O(1)
int rotationCountOptimal(const vector<int>& arr) {
    int n = arr.size();
    int lo = 0, hi = n - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > arr[hi]) {
            // Minimum is in the right half
            lo = mid + 1;
        } else {
            // arr[mid] <= arr[hi], so minimum is at mid or left half
            hi = mid;
        }
    }
    // lo == hi is the index of smallest element
    return lo;
}

// ---------------- Driver ----------------
int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << "[Brute Force] Rotation Count = " << rotationCountBrute(arr) << endl;
    cout << "[Optimal] Rotation Count = " << rotationCountOptimal(arr) << endl;
    return 0;
}

/*
Expected Output:
[Brute Force] Rotation Count = 3
[Optimal] Rotation Count = 3
*/
