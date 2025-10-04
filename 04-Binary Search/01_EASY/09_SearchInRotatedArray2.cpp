// 🔹 Problem: Search in Rotated Sorted Array II (LeetCode 81)
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
//
// Given a sorted array that has been rotated at an unknown pivot and may contain duplicates,
// check if a given target exists in the array. Return true if found, otherwise false.
//
// Example:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Approaches:
// 1. Brute Force: O(n) — scan every element
// 2. Optimal (Modified Binary Search): O(log n) on average, worst-case O(n) due to duplicates

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Idea:
// Simply iterate through the array. If any element equals target, return true.
// Time Complexity: O(n)
// Space Complexity: O(1)
bool searchBrute(const vector<int>& nums, int target) {
    for (int v : nums) {
        if (v == target) return true;
    }
    return false;
}

// ---------------- Optimal (Modified Binary Search) ----------------
// Idea:
// Use binary search but handle duplicates carefully. At each step:
// - If nums[mid] == target → return true
// - If we can reliably decide which half is sorted, search that half accordingly
// - If duplicates make it ambiguous (nums[left] == nums[mid] == nums[right]), shrink the search window by one
//
// Time Complexity: O(log n) in average cases, but can degrade to O(n) in worst cases (when many duplicates)
// Space Complexity: O(1)
bool searchOptimal(const vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return true;
        }

        // If duplicates at the ends block decision
        if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
            l++;
            r--;
        }
        // Left half is sorted
        else if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

// ---------------- Driver ----------------
int main() {
    vector<int> nums1 = {2,5,6,0,0,1,2};
    int target1 = 0;
    vector<int> nums2 = {2,5,6,0,0,1,2};
    int target2 = 3;

    cout << "[Brute]  Search1: " << (searchBrute(nums1, target1) ? "true" : "false") << endl;
    cout << "[Optimal] Search1: " << (searchOptimal(nums1, target1) ? "true" : "false") << endl;

    cout << "[Brute]  Search2: " << (searchBrute(nums2, target2) ? "true" : "false") << endl;
    cout << "[Optimal] Search2: " << (searchOptimal(nums2, target2) ? "true" : "false") << endl;

    return 0;
}
