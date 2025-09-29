/**
 * @file CountInversions.cpp
 * @brief Count the number of inversions in an array using Merge Sort.
 * 
 * Problem: Given an array, count the number of inversions.
 * An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Merge two sorted halves and count inversions
    int merge(vector<int> &arr, int low, int mid, int high) {
        int cnt = 0;
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // Count inversions
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy merged elements back into original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    // Recursive merge sort that counts inversions
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;

        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);

        return cnt;
    }

public:
    /**
     * @brief Returns the number of inversions in the array
     * @param nums Input array
     * @return Number of inversions
     */
    long long int numberOfInversions(vector<int> nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

// ------------------- Driver Code -------------------
int main() {
    vector<int> nums = {2, 4, 1, 3, 5};
    Solution sol;
    long long inversions = sol.numberOfInversions(nums);

    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
