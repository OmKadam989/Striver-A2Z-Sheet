// 🔹 Problem: Single Element in a Sorted Array (LeetCode 540)
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
//
// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once. Find this single element.  
// The solution should run in O(log n) time and O(1) space.
//
// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
//
// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Just scan the array and for each element check if its pair is next to it.
// Since everything except one element appears twice, this lets us find the unique one.
// Time Complexity: O(n)
// Space Complexity: O(1)
class SolutionBrute {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        // If all pairs matched, the single element is the last one
        return nums[n - 1];
    }
};

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use binary search. Key insight: In pairs, the first occurrence is at an even index, the second at odd.
// The unique element breaks this pairing property.  
// Use that index-parity logic to decide whether to go left or right.
// Time Complexity: O(log n)
// Space Complexity: O(1)
class SolutionOptimal {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // Make mid even (if odd, decrement by 1)
            if (mid % 2 == 1) mid--;

            // If pair relationship is intact, the single is on the right
            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;
            } else {
                // Pair broken, the unique is at mid or to the left
                hi = mid;
            }
        }
        return nums[lo];
    }
};

// ---------------- Driver ----------------
int main() {
    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    vector<int> nums2 = {3,3,7,7,10,11,11};

    SolutionBrute brute;
    SolutionOptimal opt;

    cout << "[Brute]  Unique = " << brute.singleNonDuplicate(nums1) << endl;
    cout << "[Optimal] Unique = " << opt.singleNonDuplicate(nums1) << endl;

    cout << "[Brute]  Unique = " << brute.singleNonDuplicate(nums2) << endl;
    cout << "[Optimal] Unique = " << opt.singleNonDuplicate(nums2) << endl;

    return 0;
}

/*
Expected Output:
[Brute]  Unique = 2
[Optimal] Unique = 2
[Brute]  Unique = 10
[Optimal] Unique = 10
*/
