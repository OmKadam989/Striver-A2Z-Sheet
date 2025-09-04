/*
🔹 Problem: Intersection of Two Arrays (LeetCode 349)
https://leetcode.com/problems/intersection-of-two-arrays/

Given two integer arrays nums1 and nums2, 
return an array of their intersection. 
Each element in the result must be unique, 
and the result can be returned in any order.

Example:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
*/

/* ---------------------------------------------------------------
   ✅ Approach 1: Using Set
   - Insert elements of nums1 into a set.
   - For each element in nums2, check if it exists in nums1’s set.
   - If yes, add to result set (to maintain uniqueness).
   - Convert result set to vector and return.

   Time Complexity: O(N + M) average (hash set lookups)
   Space Complexity: O(N + M)
-----------------------------------------------------------------*/
class SolutionSet {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int x : nums2) {
            if (s.count(x)) {
                result.insert(x);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

/* ---------------------------------------------------------------
   ✅ Approach 2: Two-Pointer (after sorting)
   - Sort both arrays.
   - Use two pointers to traverse.
   - If nums1[i] == nums2[j], insert into set and move both pointers.
   - If nums1[i] < nums2[j], increment i.
   - Else, increment j.
   - Convert set to vector.

   Time Complexity: O(N logN + M logM) (for sorting + traversal)
   Space Complexity: O(min(N, M)) (for set)
-----------------------------------------------------------------*/
class SolutionTwoPointer {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                s1.insert(nums1[i]);
                i++, j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return vector<int>(s1.begin(), s1.end());
    }
};
