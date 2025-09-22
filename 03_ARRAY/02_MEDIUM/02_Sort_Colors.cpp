// 🔹 Problem: Sort Colors (LeetCode 75)
// https://leetcode.com/problems/sort-colors/

/*  
Approach 1: Counting Sort (Brute Force Simulation)  
- Count the number of 0s, 1s, and 2s  
- Overwrite the array with the counted values in order  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/
class SolutionCount {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) return;

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

/*  
Approach 2: Dutch National Flag Algorithm (Optimal)  
- Use three pointers (low, mid, high)  
- low → boundary for 0  
- mid → current element being checked  
- high → boundary for 2  

Steps:  
1. If nums[mid] == 0 → swap with low, increment both  
2. If nums[mid] == 1 → just move mid  
3. If nums[mid] == 2 → swap with high, decrement high  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/
class SolutionDNF {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++, low++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
