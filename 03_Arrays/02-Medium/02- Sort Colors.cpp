// 🔹 Problem: Sort Colors (LeetCode 75)
// https://leetcode.com/problems/sort-colors/

/*  
Approach 1: Counting Sort  
- Count the number of 0s, 1s, and 2s  
- Overwrite the array based on counts  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }

        int i = 0;
        while (count0--) nums[i++] = 0;
        while (count1--) nums[i++] = 1;
        while (count2--) nums[i++] = 2;
    }
};
