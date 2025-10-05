// 🔹 Problem: Find Peak Element (LeetCode 162)
// https://leetcode.com/problems/find-peak-element/description/
//
// A peak element is one that is strictly greater than its neighbors.
// Given an array `nums`, return the index of *any* peak element.
// You may assume `nums[-1] = nums[n] = -∞` (i.e. boundaries are lower).
//
// Example:
// Input: nums = [1,2,3,1]
// Output: 2  (because 3 is a peak)
//
// Constraints imply that there is always at least one peak.  
// We want an O(log n) solution (binary search).

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Scan the array. For each index i:
//   • If i == 0, check if nums[0] > nums[1] → peak at 0
//   • If i == n-1, check if nums[n-1] > nums[n-2] → peak at n-1
//   • Otherwise, check if nums[i] > nums[i-1] && nums[i] > nums[i+1]
// Return the index once found.
// Time Complexity: O(n)
// Space Complexity: O(1)
int findPeakBrute(const vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    for (int i = 0; i < n; i++) {
        bool left_ok = (i == 0) || (nums[i] > nums[i - 1]);
        bool right_ok = (i == n - 1) || (nums[i] > nums[i + 1]);
        if (left_ok && right_ok) {
            return i;
        }
    }
    return -1;  // should never happen
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use a variant of binary search on index mid:
//   • If nums[mid] > nums[mid + 1], the peak is at mid or to the left → move `right = mid`
//   • Else (nums[mid] < nums[mid + 1]), the peak is to the right → move `left = mid + 1`
// Terminate when left == right; that's a peak index.
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findPeakOptimal(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            // descending slope, possible peak on left side (including mid)
            right = mid;
        } else {
            // ascending slope, peak must lie to the right of mid
            left = mid + 1;
        }
    }
    // left == right is one peak index
    return left;
}

// ---------------- Driver Code ----------------
int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};

    cout << "[Brute]  Peak Index = " << findPeakBrute(nums1) << endl;
    cout << "[Optimal] Peak Index = " << findPeakOptimal(nums1) << endl;

    cout << "[Brute]  Peak Index = " << findPeakBrute(nums2) << endl;
    cout << "[Optimal] Peak Index = " << findPeakOptimal(nums2) << endl;

    return 0;
}

/*
Expected Output (one possible):
[Brute]  Peak Index = 2
[Optimal] Peak Index = 2
[Brute]  Peak Index = 5
[Optimal] Peak Index = 5
*/
