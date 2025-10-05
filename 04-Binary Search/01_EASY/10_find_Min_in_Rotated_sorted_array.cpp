// 🔹 Problem: Find Minimum in Rotated Sorted Array (LeetCode 153)
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
//
// You are given a rotated sorted array (originally sorted in ascending order, then rotated).
// Return the minimum element in the rotated array.  
// All elements are **distinct** in this version.
//
// Example:
// Input: nums = [4, 5, 6, 7, 0, 1, 2]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Just scan the entire array and keep track of the minimum element.
// Time Complexity: O(n)
// Space Complexity: O(1)
class SolutionBrute {
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mn = min(mn, nums[i]);
        }
        return mn;
    }
};

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use a modified binary search that leverages the fact the array is rotated.
// Compare mid with rightmost (or with nums[r]) to decide which half to search.
// Time Complexity: O(log n)
// Space Complexity: O(1)
class SolutionOptimal {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // If mid’s value is greater than value at r, the min is to the right
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                // The min is at mid or to the left
                r = mid;
            }
        }
        // When l == r, that's the minimum
        return nums[l];
    }
};

// ---------------- Driver Code ----------------
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    SolutionBrute brute;
    SolutionOptimal opt;

    cout << "[Brute Force] Min = " << brute.findMin(nums) << endl;
    cout << "[Optimal] Min = " << opt.findMin(nums) << endl;

    return 0;
}
