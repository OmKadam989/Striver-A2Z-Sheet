// LeetCode 34. Find First and Last Position of Element in Sorted Array
// Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//
// Given a sorted array of integers and a target value, 
// return the first and last position of the target in the array.
// If the target is not found, return [-1, -1].
//
// Example:
// Input:  nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Input:  nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
// Approaches:
// 1. Brute Force: O(n) → Scan entire array, track first and last index
// 2. Optimal: O(log n) → Use Binary Search (find first & last separately)

#include <bits/stdc++.h>
using namespace std;

// ---------------- Optimal Solution (Binary Search) ----------------
class SolutionOptimal {
public:
    int firstOccurrence(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                ans = mid;
                hi = mid - 1; // keep searching left
            }
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                ans = mid;
                lo = mid + 1; // keep searching right
            }
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);
        int last = lastOccurrence(arr, target);
        return {first, last};
    }
};

// ---------------- Brute Force Solution ----------------
class SolutionBrute {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first = -1, last = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                if (first == -1) first = i; // first occurrence
                last = i; // update last occurrence
            }
        }
        return {first, last};
    }
};

// ---------------- Driver Code ----------------
int main() {
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    SolutionBrute brute;
    SolutionOptimal optimal;

    vector<int> ans1 = brute.searchRange(arr, target);
    vector<int> ans2 = optimal.searchRange(arr, target);

    cout << "Brute Force: [" << ans1[0] << "," << ans1[1] << "]" << endl;
    cout << "Optimal: [" << ans2[0] << "," << ans2[1] << "]" << endl;

    return 0;
}
