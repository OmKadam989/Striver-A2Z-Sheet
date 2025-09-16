// 🔹 Problem: Maximum Subarray (LeetCode 53)
// https://leetcode.com/problems/maximum-subarray/

/*  
Approach 1: Brute Force  
- Check every possible subarray, calculate its sum, and track the maximum.  

Time Complexity: O(n²)  
Space Complexity: O(1)  
*/
class SolutionBrute {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

/*  
Approach 2: Kadane’s Algorithm (Optimal)  
- Maintain a running sum.  
- If sum < 0, reset sum = 0.  
- Track the maximum sum found so far.  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/
class SolutionKadane {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};
