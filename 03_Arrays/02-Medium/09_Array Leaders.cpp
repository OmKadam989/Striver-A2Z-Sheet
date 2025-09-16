// 🔹 Problem: Leaders in an Array (GFG)
// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
/*
A leader in an array is an element that is greater than or equal to all the elements to its right.  
The rightmost element is always a leader.

Example:  
Input: arr = [16, 17, 4, 3, 5, 2]  
Output: [17, 5, 2]  
Explanation:  
- 17 is greater than all elements on its right.  
- 5 is greater than 2 (to its right).  
- 2 is the last element → always a leader.  

*/

// ------------------------------------------------------
// ✅ Approach 1: Optimal (Right-to-Left Traversal)
// ------------------------------------------------------
/*
Steps:
1. Start from the last element → it’s always a leader.
2. Traverse from right to left, keep track of the maximum seen so far.
3. If current element >= max_so_far, it is a leader.
4. Reverse the collected leaders at the end.

Time Complexity: O(n)  
Space Complexity: O(n) → for storing leaders
*/
class SolutionOptimal {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> leader;
        int n = arr.size();

        int maxi = arr[n-1];  // last element is always leader
        leader.push_back(maxi);

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxi) {
                leader.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(leader.begin(), leader.end()); // maintain order
        return leader;
    }
};


// ------------------------------------------------------
// ✅ Approach 2: Brute Force
// ------------------------------------------------------
/*
Steps:
1. For each element arr[i], check all elements to its right.
2. If no element greater than arr[i] exists, mark arr[i] as a leader.
3. The last element is always a leader.

Time Complexity: O(n^2)  
Space Complexity: O(n) → for storing leaders
*/
class SolutionBrute {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> leader;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) {
                leader.push_back(arr[i]);
            }
        }

        leader.push_back(arr[n - 1]); // last element always leader
        return leader;
    }
};
