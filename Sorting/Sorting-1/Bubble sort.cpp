/* Problem link:
   https://www.geeksforgeeks.org/problems/bubble-sort/1
*/

/*
Problem:
Given an array arr[], sort it using the Bubble Sort algorithm.

Example:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]

Explanation:
- Pass 1: Compare adjacent elements and swap if needed → [1, 3, 4, 7, 9]
- Pass 2: Largest element "bubbles up" to the end.
- Repeat until array is sorted.

Approach (Bubble Sort):
1. Traverse the array multiple times.
2. In each pass, compare adjacent elements:
   - If arr[j] > arr[j+1], swap them.
3. After i-th pass, the last i elements are in correct position.
4. Repeat until no swaps are needed (array sorted).

Time Complexity:
- Best Case (already sorted): O(N)
- Worst & Average Case: O(N^2)
- Space Complexity: O(1) (in-place)

Real-life Analogy:
Imagine lighter bubbles rising to the top in water.  
Here, the largest elements "bubble up" to the end of the array in each pass.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array using Bubble Sort
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        
        // Traverse through all array elements
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false; // Optimization to stop if already sorted
            
            // Last i elements are already in place
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            
            // If no elements were swapped in inner loop → array is sorted
            if (!swapped) break;
        }
    }
};

// Driver code (for testing)
int main() {
    vector<int> arr = {4, 1, 3, 9, 7};
    
    Solution ob;
    ob.bubbleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
