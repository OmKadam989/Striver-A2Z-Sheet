#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: Max Consecutive Ones (LeetCode 485)
https://leetcode.com/problems/max-consecutive-ones/

Example:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. 
The maximum number of consecutive 1s is 3.
*/

/*--------------------------------------------------------
Approach:
1. Traverse the array.
2. Keep a counter `count` to store current streak of consecutive 1s.
3. If element = 1 → increment `count`.
4. If element = 0 → reset `count` to 0.
5. Track maximum streak using `maxCount`.

Time Complexity: O(n)   → single pass
Space Complexity: O(1)  → constant space
--------------------------------------------------------*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;       // current streak of 1s
        int maxCount = 0;    // maximum streak of 1s

        for (int num : nums) {
            if (num == 1) {
                count++;                    // extend streak
                maxCount = max(maxCount, count);
            } else {
                count = 0;                  // reset on zero
            }
        }
        return maxCount;
    }
};

/*--------------------------------------------------------
🔹 Driver Code for Testing
--------------------------------------------------------*/
int main() {
    vector<int> nums = {1,1,0,1,1,1};

    Solution sol;
    cout << "Max Consecutive Ones: " << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
