/**
 * @file ReversePairs.cpp
 * @brief Count the number of reverse pairs in an array.
 * 
 * Problem: Given an array nums, count the number of reverse pairs.
 * A reverse pair is a pair (i, j) such that i < j and nums[i] > 2 * nums[j].
 * 
 * Approaches:
 * 1. Brute Force: O(n^2) time, O(1) space
 * 2. Merge Sort (Optimized): O(n log n) time, O(n) space
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force Solution ----------------
class BruteForceSolution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > 2LL * nums[j]) cnt++;
            }
        }
        return cnt;
    }
};

// ---------------- Optimized Merge Sort Solution ----------------
class OptimizedSolution {
private:
    int cnt = 0;

    // Merge two sorted halves
    void merge(vector<int> &arr, int low, int mid, int high) {
        int left = low, right = mid + 1;
        vector<int> temp;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Count reverse pairs across left and right halves
    void countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
    }

    // Merge sort helper
    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }

public:
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};

// ------------------- Driver Code -------------------
int main() {
    vector<int> nums = {1, 3, 2, 3, 1};

    BruteForceSolution bf;
    cout << "[Brute Force] Reverse Pairs: " << bf.reversePairs(nums) << endl;

    vector<int> nums2 = {1, 3, 2, 3, 1}; // copy for merge sort
    OptimizedSolution opt;
    cout << "[Optimi]()
