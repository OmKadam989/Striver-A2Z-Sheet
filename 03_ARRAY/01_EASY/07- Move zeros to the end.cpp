/*
🔹 Problem: Move Zeroes (LeetCode 283)
https://leetcode.com/problems/move-zeroes/

Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Example:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

/* ---------------------------------------------------------------
   ✅ Approach 1: Brute Force (Extra Array)
   Steps:
   1. Traverse array and push all non-zero elements into a new array.
   2. Count number of zeroes and push them at the end.
   3. Copy everything back to original array.

   Time Complexity: O(N)
   Space Complexity: O(N)
-----------------------------------------------------------------*/
class SolutionBruteForce {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr;
        int zeroCount = 0;

        /* Collect non-zero elements */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                arr.push_back(nums[i]);
            } else {
                zeroCount++;
            }
        }

        /* Add zeroes at the end */
        for (int i = 0; i < zeroCount; i++) {
            arr.push_back(0);
        }

        /* Copy back to nums */
        for (int j = 0; j < nums.size(); j++) {
            nums[j] = arr[j];
        }
    }
};

/* ---------------------------------------------------------------
   ✅ Approach 2: Optimal (Two-Pointer In-place)
   Steps:
   1. Find the first index of zero (j).
   2. Traverse the array:
      - Whenever a non-zero element is found, swap it with nums[j].
      - Move j forward.
   3. This ensures all non-zero elements move forward 
      and zeroes shift to the back automatically.

   Time Complexity: O(N)
   Space Complexity: O(1)
-----------------------------------------------------------------*/
class SolutionOptimal {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;  /* index of first zero */
        int n = nums.size();

        /* Find first zero */
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) return;  /* No zero found */

        /* Shift non-zero elements forward */
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
