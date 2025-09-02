// 🔹 Problem: Rotate Array (LeetCode 189)
// https://leetcode.com/problems/rotate-array/

// ✅ Brute Force Approach (Using Extra Array)
// 1. Store last k elements into a temporary array.
// 2. Store the remaining n-k elements.
// 3. Copy everything back into original array.
//
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;        // empty array
        k = k % n;                 // normalize k
        if (k == 0) return;        // no rotation needed

        vector<int> rotate1;

        // take last k elements
        for (int i = n - k; i < n; i++) {
            rotate1.push_back(nums[i]);
        }

        // take first n-k elements
        for (int i = 0; i < n - k; i++) {
            rotate1.push_back(nums[i]);
        }

        // copy back to nums
        for (int j = 0; j < n; j++) {
            nums[j] = rotate1[j];
        }
    }
};
