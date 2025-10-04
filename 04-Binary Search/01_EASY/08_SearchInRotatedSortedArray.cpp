// 🔹 Problem: Search in Rotated Sorted Array (LeetCode 33)
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//
// Given a sorted array `nums` that has been rotated at an unknown pivot, 
// and a target value, return the index of target if it exists, otherwise return −1.
// You may assume no duplicate exists in the array.
//
// Example:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Simply scan the entire array. If nums[i] == target, return i.
// If not found, return -1.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
int searchBrute(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

// ---------------- Optimal (Modified Binary Search) ----------------
// Approach:
// Use a variant of binary search. At each step:
// 1. Compute mid. If nums[mid] == target, return mid.
// 2. Determine which half (left or right) is properly sorted.
// 3. If target lies in that sorted half, restrict search there; otherwise search the other half.
//
// Because one side is always sorted in a rotated sorted array, you can eliminate half each time. :contentReference[oaicite:0]{index=0}
// Time Complexity: O(log n)
// Space Complexity: O(1)
int searchOptimal(const vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;

        // Determine which side is sorted
        if (nums[lo] <= nums[mid]) {
            // Left half [lo..mid] is sorted
            if (nums[lo] <= target && target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            // Right half [mid..hi] is sorted
            if (nums[mid] < target && target <= nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

// ---------------- Driver ----------------
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << "[Brute Force] Index: " << searchBrute(nums, target) << endl;
    cout << "[Optimal] Index: " << searchOptimal(nums, target) << endl;

    return 0;
}

/*
Expected Output:
[Brute Force] Index: 4
[Optimal] Index: 4
*/
