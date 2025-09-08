// 🔹 Problem: Two Sum (LeetCode 1)
// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

/* 
-------------------------------------------------
1️⃣ Brute Force Approach
- Check every pair using nested loops
- Return indices if sum == target
Time Complexity: O(n²)
Space Complexity: O(1)
-------------------------------------------------
*/
class SolutionBrute {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/* 
-------------------------------------------------
2️⃣ Hashing Approach (Best / Optimized)
- Use a hash map to store value -> index
- Check if (target - nums[i]) exists in map
Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------
*/
class SolutionHash {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

/* 
-------------------------------------------------
3️⃣ Sorting + Two Pointers (Not valid for index-based answer unless we store original indices)
- Sort array, use two-pointer to find pair
- But since indices matter, we must store original indices first
Time Complexity: O(n log n)
Space Complexity: O(n) (for storing indices)
-------------------------------------------------
*/
class SolutionTwoPointers {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr; // {value, index}
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end()); // sort by values
        int l = 0, r = arr.size() - 1;

        while (l < r) {
            int sum = arr[l].first + arr[r].first;
            if (sum == target) {
                return {arr[l].second, arr[r].second};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
