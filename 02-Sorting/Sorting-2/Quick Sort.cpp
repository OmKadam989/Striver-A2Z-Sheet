/* Problem link:
   https://www.geeksforgeeks.org/problems/quick-sort/1
*/

/*
Problem:
Given an array arr[], implement Quick Sort to sort the array.

Example:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]

Explanation:
- Quick Sort picks a pivot element.
- It rearranges elements so that:
    Left side  -> elements smaller than pivot
    Right side -> elements greater than pivot
- Recursively sort both halves.

Approach (Divide & Conquer):
1. Choose a pivot (here we take the first element).
2. Partition the array:
   - Move all smaller elements to the left.
   - Move all larger elements to the right.
3. Recursively sort the left and right partitions.

Time Complexity:
- Best & Average: O(N log N)  (balanced partitions)
- Worst: O(N^2)  (already sorted array, poor pivot choice)
- Space: O(1)  (in-place), recursion stack O(log N) to O(N)

Real-life Analogy:
Think of lining up students by height:
- Pick one student (pivot).
- Send shorter ones to the left, taller to the right.
- Repeat the process in each group until the line is sorted.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Partition function: places pivot at its correct position
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];   // choose first element as pivot
        int i = low + 1;        // left pointer
        int j = high;           // right pointer
        
        while (i <= j) {
            // Move i right while elements are smaller than pivot
            if (arr[i] < pivot) {
                i++;
            }
            // Move j left while elements are greater than pivot
            else if (arr[j] > pivot) {
                j--;
            }
            // If arr[i] >= pivot and arr[j] <= pivot → swap
            else {
                swap(arr[i++], arr[j--]);
            }
        }
        // Place pivot in its correct position
        swap(arr[low], arr[j]);
        return j; // return pivot index
    }

    // Recursive Quick Sort
    void quickSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        
        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);   // sort left part
        quickSort(arr, index + 1, high);  // sort right part
    }
};

// Driver code (for testing)
int main() {
    vector<int> arr = {4, 1, 3, 9, 7};
    
    Solution ob;
    ob.quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
