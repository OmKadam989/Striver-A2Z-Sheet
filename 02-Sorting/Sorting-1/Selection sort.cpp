/* Problem link:
   https://www.geeksforgeeks.org/problems/selection-sort/1
*/

/*
Problem:
Given an array arr[], sort it using the Selection Sort algorithm.

Example:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]

Explanation:
- Initially: [4, 1, 3, 9, 7]
- Select minimum (1) from unsorted part → swap with first → [1, 4, 3, 9, 7]
- Next, select minimum (3) from remaining → [1, 3, 4, 9, 7]
- Next, select minimum (4) → stays same → [1, 3, 4, 9, 7]
- Next, select minimum (7) → swap with 9 → [1, 3, 4, 7, 9]
- Finally, array is sorted.

Approach (Selection Sort):
1. Divide the array into two parts → sorted (left) and unsorted (right).
2. From the unsorted part, find the minimum element.
3. Swap it with the first element of the unsorted part.
4. Move the boundary of the sorted part one step to the right.
5. Repeat until the array is fully sorted.

Time Complexity:
- Worst, Average, Best: O(N^2) comparisons.
- Space Complexity: O(1) (in-place sorting).

Real-life Analogy:
Imagine you are arranging books by height on a shelf.  
You repeatedly look through the unsorted pile, pick the *shortest* book, 
and place it in its correct position on the left.  
Repeat this until all books are ordered.
*/

class Solution {
  public:
    // Function to perform Selection Sort on the given array
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        
        // Move boundary of sorted subarray one by one
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;  // Assume current element is minimum
            
            // Find the minimum element in unsorted part
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Update minimum index
                }
            }
            
            // Swap the found minimum with the first element of unsorted part
            swap(arr[i], arr[minIndex]);
        }
    }
};
