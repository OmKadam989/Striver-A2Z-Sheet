// 🔹 Problem: Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//
// You are given an integer array `nums` and an integer `threshold`.
// Choose a positive integer `divisor` such that the sum of `ceil(nums[i] / divisor)`
// for all elements in `nums` is less than or equal to `threshold`.
// Return the smallest possible divisor satisfying this condition.
//
// Example:
// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
//
// Explanation: ceil(1/5)+ceil(2/5)+ceil(5/5)+ceil(9/5) = 1+1+1+2 = 5 ≤ 6
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// Helper Function → calculates the sum of ceilings for a given divisor
int sumWithDivisor(vector<int> &nums, int divisor) {
    int total = 0;
    for (int num : nums)
        total += ceil((double)num / divisor);
    return total;
}

// ---------------- Brute Force ----------------
// Approach:
// Try all divisors from 1 to max(nums).
// For each divisor, calculate the sum of ceilings.
// The first divisor giving sum <= threshold is our answer.
//
// Time Complexity: O(n * max(nums))
// Space Complexity: O(1)
int smallestDivisorBrute(vector<int>& nums, int threshold) {
    int maxElem = *max_element(nums.begin(), nums.end());

    for (int d = 1; d <= maxElem; d++) {
        if (sumWithDivisor(nums, d) <= threshold)
            return d;
    }
    return maxElem;
}

// ---------------- Optimal Binary Search ----------------
// Approach:
// Binary search the answer between [1, max(nums)].
// If current mid (divisor) gives sum <= threshold, it might be the answer → move left.
// Else, move right.
//
// Time Complexity: O(n * log(max(nums)))
// Space Complexity: O(1)
int smallestDivisorOptimal(vector<int>& nums, int threshold) {
    int lo = 1, hi = *max_element(nums.begin(), nums.end());
    int ans = hi;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (sumWithDivisor(nums, mid) <= threshold) {
            ans = mid;      // possible answer
            hi = mid - 1;   // try smaller divisor
        } else {
            lo = mid + 1;   // need larger divisor
        }
    }
    return ans;
}

// ---------------- Driver Code ----------------
int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Brute Force: " << smallestDivisorBrute(nums, threshold) << endl;
    cout << "Optimal: " << smallestDivisorOptimal(nums, threshold) << endl;

    return 0;
}

/*
Expected Output:
Brute Force: 5
Optimal: 5
*/
