// 🔹 Problem: Split Array Largest Sum (LeetCode 410)
// https://leetcode.com/problems/split-array-largest-sum/
//
// You are given an array nums and an integer m.
// Split the array into m non-empty continuous subarrays
// such that the largest sum among these subarrays is minimized.
// Return that minimized largest sum.
//
// Example:
// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation: The optimal split is [7,2,5] and [10,8],
//              with the largest sum being 18.

#include <bits/stdc++.h>
using namespace std;

// =========================================================
// 🧩 Brute Force (Recursive DP) Approach
// =========================================================
//
// Approach:
// Try all ways to split the array into `m` parts and choose
// the one that minimizes the largest subarray sum.
// We use recursion + memoization (DP) to avoid recomputation.
//
// Time Complexity: O(n^2 * m)
// Space Complexity: O(n * m)
//
// Note: This is fine for small inputs but inefficient for large ones.
//
int helperBrute(int i, int m, vector<int>& nums, vector<vector<int>>& dp) {
    int n = nums.size();
    if (m == 1) {
        // Base case: one partition left → take the sum of the remaining elements
        return accumulate(nums.begin() + i, nums.end(), 0);
    }

    if (dp[i][m] != -1) return dp[i][m];

    int curSum = 0;
    int res = INT_MAX;

    for (int j = i; j <= n - m; j++) {
        curSum += nums[j];
        int largest = max(curSum, helperBrute(j + 1, m - 1, nums, dp));
        res = min(res, largest);

        // Small optimization: if current sum exceeds best found, break early
        if (curSum > res) break;
    }

    return dp[i][m] = res;
}

int splitArrayBrute(vector<int>& nums, int m) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    return helperBrute(0, m, nums, dp);
}

// =========================================================
// ⚡ Optimal Approach (Binary Search + Greedy Validation)
// =========================================================
//
// Intuition:
//  - The answer (minimum largest subarray sum) lies between:
//      low = max(nums)  (largest single element)
//      high = sum(nums) (all elements in one subarray)
//  - We binary search on this range and check whether
//    a given max sum `mid` can split the array into ≤ m parts.
//
// Greedy check: If sum exceeds mid, start a new subarray.
//
// Time Complexity: O(n * log(sum(nums)))
// Space Complexity: O(1)
//
int countSubarrays(vector<int>& nums, long long maxSum) {
    long long curSum = 0;
    int count = 1;
    for (int x : nums) {
        if (curSum + x > maxSum) {
            count++;
            curSum = x;
        } else {
            curSum += x;
        }
    }
    return count;
}

int splitArrayOptimal(vector<int>& nums, int m) {
    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        int needed = countSubarrays(nums, mid);
        if (needed <= m) {
            ans = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // need bigger max sum
        }
    }
    return ans;
}

// =========================================================
// 🧠 Driver Function
// =========================================================
int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;

    cout << "🔹 Brute Force Result:  " << splitArrayBrute(nums, m) << endl;
    cout << "⚡ Optimal Result:      " << splitArrayOptimal(nums, m) << endl;

    return 0;
}

/*
================= 🧾 Expected Output =================
🔹 Brute Force Result:  18
⚡ Optimal Result:      18
======================================================
*/
