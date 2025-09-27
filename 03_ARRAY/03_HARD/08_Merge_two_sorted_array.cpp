/*
LeetCode 88. Merge Sorted Array
Problem Link: https://leetcode.com/problems/merge-sorted-array/

📝 Problem:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums2 into nums1 as one sorted array. nums1 has length m+n with extra 0s at the end.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

Output:
nums1 = [1,2,2,3,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------------------------------
1️⃣ Brute Force
Approach:
- Copy all elements of nums2 into nums1's empty slots.
- Sort the entire nums1 array.
- Very simple but inefficient since arrays are already sorted.

Time Complexity: O((m+n) log(m+n))
Space Complexity: O(1)
--------------------------------------------------------- */
class SolutionBrute {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

/* ---------------------------------------------------------
2️⃣ Better Approach (Two Pointers + Extra Array)
Approach:
- Use two pointers, one for nums1 (up to m) and one for nums2.
- Compare and push the smaller element into a temporary result array.
- Copy result back to nums1.

Time Complexity: O(m+n)
Space Complexity: O(m+n)
--------------------------------------------------------- */
class SolutionBetter {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) result.push_back(nums1[i++]);
            else result.push_back(nums2[j++]);
        }
        while (i < m) result.push_back(nums1[i++]);
        while (j < n) result.push_back(nums2[j++]);

        for (int k = 0; k < m+n; k++) {
            nums1[k] = result[k];
        }
    }
};

/* ---------------------------------------------------------
3️⃣ Optimal Approach ✅ (In-Place, Two Pointers from Back)
Approach:
- Start from the back of nums1 and nums2.
- Place the larger element at the end (nums1[k]).
- This avoids overwriting values and uses no extra space.
- Copy remaining nums2 if any.

Time Complexity: O(m+n)
Space Complexity: O(1)
--------------------------------------------------------- */
class SolutionOptimal {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};

// 🔹 Driver Code (Example)
int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    // Brute
    vector<int> a1 = nums1;
    SolutionBrute sb;
    sb.merge(a1, m, nums2, n);
    cout << "Brute Force: "; for (int x : a1) cout << x << " "; cout << endl;

    // Better
    vector<int> a2 = nums1;
    SolutionBetter sbet;
    sbet.merge(a2, m, nums2, n);
    cout << "Better:      "; for (int x : a2) cout << x << " "; cout << endl;

    // Optimal
    vector<int> a3 = nums1;
    SolutionOptimal so;
    so.merge(a3, m, nums2, n);
    cout << "Optimal:     "; for (int x : a3) cout << x << " "; cout << endl;

    return 0;
}
