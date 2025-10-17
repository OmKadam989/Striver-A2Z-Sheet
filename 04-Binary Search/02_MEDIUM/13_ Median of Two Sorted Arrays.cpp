// 🔹 Problem: Median of Two Sorted Arrays (LeetCode 4)
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//
// Given two sorted arrays nums1 and nums2 (length m and n), find the median
// of the combined set of numbers in O(log(m + n)) time.  
// If the total length is odd, return the middle element; if even, return the average of the two middle ones.

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force (Merge) ----------------
// Approach:
// Merge the two sorted arrays into one sorted array (or simulate merge) and then
// compute the median from that merged result.
//
// Time Complexity: O(m + n)
// Space Complexity: O(m + n)
double findMedianBrute(const vector<int>& a, const vector<int>& b) {
    int m = a.size(), n = b.size();
    vector<int> merged;
    merged.reserve(m + n);
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
    }
    while (i < m) merged.push_back(a[i++]);
    while (j < n) merged.push_back(b[j++]);

    int total = m + n;
    if (total % 2 == 1) {
        return merged[total / 2];
    } else {
        return (merged[total/2 - 1] + merged[total/2]) / 2.0;
    }
}

// ---------------- Optimal (Binary Search / Divide & Conquer) ----------------
// Approach (finding the k-th element):
// The median can be thought of as the ( (m + n + 1) / 2 )-th and possibly ( (m + n + 2) / 2 )-th smallest elements.
// Use a helper that finds the k-th smallest element in two sorted arrays in O(log(m + n)) time.
// Then compute median from those k-th elements.

int findKth(const vector<int>& a, int i_start,
            const vector<int>& b, int j_start, int k) {
    // If a is exhausted, return from b
    if (i_start >= a.size()) {
        return b[j_start + k - 1];
    }
    // If b is exhausted
    if (j_start >= b.size()) {
        return a[i_start + k - 1];
    }
    // If k == 1, return min of first elements
    if (k == 1) {
        return min(a[i_start], b[j_start]);
    }
    // Divide k into two parts
    int midA = INT_MAX, midB = INT_MAX;
    int half = k / 2;
    if (i_start + half - 1 < a.size()) {
        midA = a[i_start + half - 1];
    }
    if (j_start + half - 1 < b.size()) {
        midB = b[j_start + half - 1];
    }
    if (midA < midB) {
        // discard first half elements of a (i_start to i_start + half - 1)
        return findKth(a, i_start + half, b, j_start, k - half);
    } else {
        // discard first half elements of b
        return findKth(a, i_start, b, j_start + half, k - half);
    }
}

double findMedianOptimal(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int total = m + n;

    int k1 = (total + 1) / 2;
    int k2 = (total + 2) / 2;

    // In odd case, k1 == k2, so it's the same element
    double med1 = findKth(nums1, 0, nums2, 0, k1);
    double med2 = findKth(nums1, 0, nums2, 0, k2);
    return (med1 + med2) / 2.0;
}

// ---------------- Driver ----------------
int main() {
    vector<int> a1 = {1, 3};
    vector<int> b1 = {2};
    cout << "[Brute]   Median = " << findMedianBrute(a1, b1)
         << "\n[Optimal] Median = " << findMedianOptimal(a1, b1) << endl;

    vector<int> a2 = {1, 2};
    vector<int> b2 = {3, 4};
    cout << "[Brute]   Median = " << findMedianBrute(a2, b2)
         << "\n[Optimal] Median = " << findMedianOptimal(a2, b2) << endl;

    return 0;
}

/*
Expected Output:
[Brute]   Median = 2
[Optimal] Median = 2
[Brute]   Median = 2.5
[Optimal] Median = 2.5
*/
