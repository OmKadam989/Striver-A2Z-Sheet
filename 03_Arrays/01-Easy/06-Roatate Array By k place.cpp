/*
🔹 Problem: Rotate Array (LeetCode 189)
https://leetcode.com/problems/rotate-array/

Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.

Example:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Explanation:
rotate 1 step to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

/* ---------------------------------------------------------------
   ✅ Approach 1: Brute Force (Using Extra Array)
   Steps:
   1. Store last k elements into a temporary array.
   2. Store the remaining n-k elements.
   3. Copy everything back into original array.

   Time Complexity: O(N)
   Space Complexity: O(N)
-----------------------------------------------------------------*/
class SolutionBruteForce {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;        /* empty array */
        k = k % n;                 /* normalize k */
        if (k == 0) return;        /* no rotation needed */

        vector<int> temp;

        /* take last k elements */
        for (int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }

        /* take first n-k elements */
        for (int i = 0; i < n - k; i++) {
            temp.push_back(nums[i]);
        }

        /* copy back to nums */
        for (int j = 0; j < n; j++) {
            nums[j] = temp[j];
        }
    }
};

/* ---------------------------------------------------------------
   ✅ Approach 2: Optimal (In-place Reversal Algorithm)
   Steps:
   1. Reverse first n-k elements
   2. Reverse last k elements
   3. Reverse entire array

   Time Complexity: O(N)
   Space Complexity: O(1)
-----------------------------------------------------------------*/
class SolutionOptimal {
public:
    void reverse1(vector<int>& arr, int left, int right) {
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  /* normalize k */

        reverse1(nums, 0, n - k - 1);   /* step 1 */
        reverse1(nums, n - k, n - 1);   /* step 2 */
        reverse1(nums, 0, n - 1);       /* step 3 */
    }
};
