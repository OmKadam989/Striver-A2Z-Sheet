/*
🔹 Problem: Who Will Win (GFG)
https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

Given a sorted array arr[] of size N and a number K, 
the task is to check if K is present in the array or not.

Example:
Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Explanation: Since 6 is present in the array at index 4, output is true.
*/

/* ---------------------------------------------------------------
   ✅ Approach 1: Brute Force (Linear Search)
   - Traverse the array and check each element.
   - If element matches K → return true, else false.

   Time Complexity: O(N)
   Space Complexity: O(1)
-----------------------------------------------------------------*/
class SolutionBruteForce {
public:
    bool searchInSorted(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == k) return true;
        }
        return false;
    }
};