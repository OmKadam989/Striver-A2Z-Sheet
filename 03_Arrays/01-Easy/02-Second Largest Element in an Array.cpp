// Problem: Second Largest Element in Array
// Link: https://www.geeksforgeeks.org/problems/second-largest3735/1
// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element is 35 and the second largest is 34.

// ------------------------------------------------------------
// Approach 1: Brute Force (Sorting + Linear Scan)
// 1. Sort the array (O(N logN))
// 2. Take the largest element.
// 3. Scan from left and find the maximum element not equal to largest.
// Time Complexity: O(N logN + N) ≈ O(N logN)
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionBrute {
  public:
    int getSecondLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int largest = arr.back();
        
        int secondLargest = -1;
        for (int i = arr.size()-2; i >= 0; i--) {
            if (arr[i] != largest) {
                secondLargest = arr[i];
                break;
            }
        }
        return secondLargest;
    }
};

// ------------------------------------------------------------
// Approach 2: Better (Two Pass)
// 1. Find the largest element in one pass.
// 2. In another pass, find the maximum element smaller than largest.
// Time Complexity: O(N + N) = O(N)
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionBetter {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[0];
        int secondLargest = INT_MIN;
        
        // Pass 1: Find largest
        for (int i = 1; i < n; i++) {
            if (arr[i] > largest) largest = arr[i];
        }
        
        // Pass 2: Find second largest
        for (int i = 0; i < n; i++) {
            if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};

// ------------------------------------------------------------
// Approach 3: Optimal (Single Pass)
// 1. Keep track of largest and secondLargest while traversing.
// 2. Update secondLargest when a new largest is found.
// Time Complexity: O(N)
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionOptimal {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[0];
        int secondLargest = -1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } 
            else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
};
