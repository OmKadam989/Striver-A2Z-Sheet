// Problem: Largest Element in Array
// Link: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
// Input: arr[] = [1, 8, 7, 56, 90]
// Output: 90
// Explanation: The largest element of the given array is 90.

// ------------------------------------------------------------
// Approach 1: Brute Force
// Check each element against all others.
// If no element is greater, then it’s the largest.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionBrute {
public:
    int largest(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            bool isLargest = true;
            for (int j = 0; j < n; j++) {
                if (arr[j] > arr[i]) {
                    isLargest = false;
                    break;
                }
            }
            if (isLargest) return arr[i];
        }
        return -1; // edge case
    }
};

// ------------------------------------------------------------
// Approach 2: Better Approach
// Traverse the array once, keep track of max value.
// Time Complexity: O(N)
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionBetter {
public:
    int largest(vector<int>& arr) {
        int maxi = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }
        return maxi;
    }
};

// ------------------------------------------------------------
// Approach 3: Optimal Approach (using STL)
// Use *max_element from <algorithm>.
// Time Complexity: O(N)
// Space Complexity: O(1)
// ------------------------------------------------------------

#include <algorithm>
class SolutionOptimal {
public:
    int largest(vector<int>& arr) {
        return *max_element(arr.begin(), arr.end());
    }
};
