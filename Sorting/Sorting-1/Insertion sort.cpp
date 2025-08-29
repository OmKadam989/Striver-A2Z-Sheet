/* Problem link:
   https://www.geeksforgeeks.org/problems/insertion-sort/1
*/

/*
Problem:
Given an array arr[], sort it using the Insertion Sort algorithm.

Example:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]

Explanation:
- Take 1 and insert it in correct position → [1, 4, 3, 9, 7]
- Take 3 and insert it in correct position → [1, 3, 4, 9, 7]
- Take 9 → already in correct place → [1, 3, 4, 9, 7]
- Take 7 and insert before 9 → [1, 3, 4, 7, 9]

Approach (Insertion Sort):
1. Start from the 2nd element, assume the left part is already sorted.
2. Compare the current element with previous elements.
3. Shift elements greater than current to the right.
4. Insert the current element in its correct position.
5. Repeat until array is sorted.

Time Complexity:
- Best Case (already sorted): O(N)
- Worst & Average Case: O(N^2)
- Space Complexity: O(1) (in-place)

Real-life Analogy:
Imagine sorting a hand of playing cards.  
You pick the next card and insert it into its correct position among the already sorted cards.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform Insertion Sort
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        // Start from the 2nd element (index 1)
        for (int i = 1; i < n; i++) {
            // Compare with sorted part [0...i-1]
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j - 1]);  // Swap if smaller
                } else {
                    break; // Already in correct place
                }
            }
        }
    }
};

// Driver code (for testing)
int main() {
    vector<int> arr = {4, 1, 3, 9, 7};
    
    Solution ob;
    ob.insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
