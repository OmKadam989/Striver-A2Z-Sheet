// 🔹 Problem: Remove Duplicates from Sorted Array (LeetCode 26)
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// ✅ Brute Force Approach (Using Set)
// 1. Insert all elements into a set (unique + sorted automatically).
// 2. Copy back to original array from set.
// 3. Return new size.
//
// Time Complexity: O(N logN)  [insertions into set]
// Space Complexity: O(N)      [extra set space]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> s1;
        
        for (int i = 0; i < n; i++) {
            s1.insert(nums[i]);
        }
        
        int indx = 0;
        for (auto it : s1) {
            nums[indx] = it;
            indx++;
        }
        
        return indx;
    }
};

// ✅ Optimized Approach (Two Pointers)
// 1. Keep pointer i at the last unique element.
// 2. Traverse with j, if arr[j] != arr[i], move i forward and update arr[i].
// 3. Return i+1 (length of unique subarray).
//
// Time Complexity: O(N)    [single pass]
// Space Complexity: O(1)   [in-place]

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
        for (int j = 1; j < arr.size(); j++) {
            if (arr[i] != arr[j]) {
                arr[i + 1] = arr[j];
                i++;
            }
        }
        return i + 1;
    }
};
