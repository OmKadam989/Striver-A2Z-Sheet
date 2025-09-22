// 🔹 Problem: Next Permutation (LeetCode 31)
// https://leetcode.com/problems/next-permutation/

/*
Problem Explanation:
You are given an array of integers representing a permutation.
The task is to rearrange the numbers into the lexicographically 
next greater permutation of numbers.

- If such an arrangement is possible, return it.
- If not (the array is in descending order = last permutation), 
  return the smallest permutation (ascending order).

---

Example 1:
Input:  nums = [1, 2, 3]
Output: [1, 3, 2]
Explanation: The next permutation after [1,2,3] is [1,3,2].

Example 2:
Input:  nums = [3, 2, 1]
Output: [1, 2, 3]
Explanation: [3,2,1] is the last permutation, 
so we return the first (sorted ascending).

Example 3:
Input:  nums = [1, 1, 5]
Output: [1, 5, 1]

---

Approach 1: Manual Implementation (Optimal)
Steps:
1. Find the first index `indx` from the right such that nums[indx] < nums[indx+1].
   - If no such index exists, the array is in descending order → reverse it.
2. Find the smallest number greater than nums[indx] to the right.
3. Swap them.
4. Reverse the subarray from indx+1 to end.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class SolutionManual {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = -1;

        // Step 1: Find first decreasing element from right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                indx = i;
                break;
            }
        }

        // If array is in descending order → last permutation
        if (indx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find just larger element to the right
        for (int i = n - 1; i > indx; i--) {
            if (nums[i] > nums[indx]) {
                swap(nums[i], nums[indx]);
                break;
            }
        }

        // Step 3: Reverse suffix
        reverse(nums.begin() + indx + 1, nums.end());
    }
};

/*
Approach 2: Using STL
- C++ STL provides `next_permutation()` which directly computes 
  the next lexicographical permutation.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class SolutionSTL {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
