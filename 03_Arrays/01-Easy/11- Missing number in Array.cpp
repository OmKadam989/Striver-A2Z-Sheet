#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: Missing Number (LeetCode 268)
https://leetcode.com/problems/missing-number/

Example:
Input: nums = [3,0,1]
Output: 2

Explanation:
n = 3, numbers should be [0,1,2,3].
Missing number = 2
*/

/*--------------------------------------------------------
  1. Brute Force
  - For each number from 0 to n, check if it's present.
  - If not, that's the missing number.

  Time Complexity: O(n²)
  Space Complexity: O(1)
--------------------------------------------------------*/
class SolutionBrute {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) return i;
        }
        return -1;
    }
};

/*--------------------------------------------------------
  2. Sorting
  - Sort array and check index vs value mismatch.
  
  Time Complexity: O(n log n)
  Space Complexity: O(1)
--------------------------------------------------------*/
class SolutionSorting {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i != nums[i]) return i;
        }
        return n;
    }
};

/*--------------------------------------------------------
  3. Hashing
  - Use extra array/hash to mark presence of numbers.
  
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------------------------------*/
class SolutionHashing {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }
        for (int i = 0; i <= n; i++) {
            if (hash[i] == 0) return i;
        }
        return -1;
    }
};

/*--------------------------------------------------------
  4. Sum Formula
  - Expected sum = n*(n+1)/2
  - Subtract actual sum to find missing number.
  
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------------------------*/
class SolutionSum {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (n * (n + 1)) / 2;
        int sumElement = 0;
        for (int num : nums) {
            sumElement += num;
        }
        return total - sumElement;
    }
};

/*--------------------------------------------------------
  5. XOR Method (Two Loops)
  - XOR all numbers from 0..n
  - XOR all numbers from nums[]
  - Missing number = XOR1 ^ XOR2
  
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------------------------*/
class SolutionXOR1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR1 = 0, XOR2 = 0;
        for (int i = 0; i <= n; i++) XOR1 ^= i;
        for (int i = 0; i < n; i++) XOR2 ^= nums[i];
        return XOR1 ^ XOR2;
    }
};

/*--------------------------------------------------------
  6. XOR Method (Single Loop)
  - Do XOR of indices & nums[] in one pass.
  
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------------------------*/
class SolutionXOR2 {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            xor2 ^= nums[i];
            xor1 ^= (i + 1);
        }
        return xor1 ^ xor2;
    }
};


