/* Problem link:
   https://www.geeksforgeeks.org/problems/merge-sort/1
*/

/*
Problem:
Given an array arr[], implement Merge Sort to sort the array.

Example:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]

Explanation:
- Merge Sort works by recursively dividing the array into halves.
- Then merges the two halves in a sorted manner.

Approach (Divide & Conquer):
1. Divide:
   - Recursively split the array into two halves until only single elements remain.
2. Conquer:
   - Merge the two halves into a sorted array.
3. Continue merging until the entire array is sorted.

Time Complexity:
- Best, Average, Worst: O(N log N)  (since array is divided and merged)
- Space Complexity: O(N)  (temporary array used for merging)

Real-life Analogy:
Imagine splitting a pile of cards into halves repeatedly until you get individual cards,  
then combine them back in sorted order step by step until the whole deck is sorted.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to merge two halves
    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        
        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        // Copy remaining elements (if any)
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        // Copy back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    // Recursive Merge Sort
    void mergeSortRec(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        
        int mid = (low + high) / 2;
        
        // Sort left half
        mergeSortRec(arr, low, mid);
        
        // Sort right half
        mergeSortRec(arr, mid + 1, high);
        
        // Merge sorted halves
        merge(arr, low, mid, high);
    }
    
    // Main function
    void mergeSort(vector<int>& arr, int l, int r) {
        mergeSortRec(arr, l, r);
    }
};

// Driver code (for testing)
int main() {
    vector<int> arr = {4, 1, 3, 9, 7};
    
    Solution ob;
    ob.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
