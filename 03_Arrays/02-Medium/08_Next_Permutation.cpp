class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // 1. Find the first index i such that nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // 2. Find the rightmost index j such that nums[j] > nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // 3. Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }

        // 4. Reverse the suffix starting from i+1
        reverse(nums.begin() + i + 1, nums.end());
    
    }
};