// Search Insert Position
// LeetCode: https://leetcode.com/problems/search-insert-position/
//
// Problem:
// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be inserted in order.
// Must run in O(log n) time complexity.
//
// Example:
// Input: nums = [1,3,5,6], target = 5
// Output: 2
//
// Input: nums = [1,3,5,6], target = 2
// Output: 1
//
// Approaches:
// 1. Brute Force: O(n), linear scan
// 2. Optimal: O(log n), binary search

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Scan the array from left to right.
// Return the first index where nums[i] >= target.
// If none, insert at the end.
int searchInsertBrute(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] >= target) return i;
    }
    return n; // if target is greater than all elements
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use binary search to find the position.
// - If nums[mid] == target → return mid.
// - If nums[mid] > target → move left (end = mid - 1), record mid as possible answer.
// - If nums[mid] < target → move right (start = mid + 1).
// Finally, 'index' will be the correct position.
int searchInsertOptimal(vector<int>& nums, int target) {
    int n = nums.size();
    int start = 0, end = n - 1;
    int index = n; // default = insert at end

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            index = mid;    // possible insertion position
            end = mid - 1;  // move left
        } else {
            start = mid + 1; // move right
        }
    }
    return index;
}

// ---------------- Driver ----------------
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << "[Brute Force] Insert position: " << searchInsertBrute(nums, target) << endl;
    cout << "[Optimal] Insert position: " << searchInsertOptimal(nums, target) << endl;

    return 0;
}

/*
Expected Output:
[Brute Force] Insert position: 2
[Optimal] Insert position: 2
*/
