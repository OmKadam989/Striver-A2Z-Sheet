// 🔹 Problem: Longest Consecutive Sequence (LeetCode 128)
// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.  

Example:  
Input: nums = [100,4,200,1,3,2]  
Output: 4  
Explanation: The longest consecutive sequence is [1, 2, 3, 4].  
Therefore, the length is 4.
*/


// ------------------------------------------------------
// ✅ Approach 1: Brute Force (Using Linear Search)
// ------------------------------------------------------
/*
Steps:
1. For every element, check if the next consecutive element exists in the array.
2. Keep counting until no further consecutive number is found.
3. Track the maximum length.

Time Complexity: O(n^2) → for each element, we do linear search.  
Space Complexity: O(1)
*/
class SolutionBrute {
public:
    bool linearSearch(vector<int> &a, int target) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == target) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 1;

            while (linearSearch(nums, x + 1)) {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};


// ------------------------------------------------------
// ✅ Approach 2: Optimal (Using Hash Set)
// ------------------------------------------------------
/*
Steps:
1. Insert all numbers into an unordered_set for O(1) lookup.
2. For each element, check if it is the start of a sequence 
   (i.e., x-1 is not present).
3. If yes, expand the sequence until numbers are consecutive.
4. Track the maximum length.

Time Complexity: O(n)  
Space Complexity: O(n)
*/
class SolutionOptimal {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) { // start of a sequence
                int currNum = num;
                int cnt = 1;

                while (st.find(currNum + 1) != st.end()) {
                    currNum++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
