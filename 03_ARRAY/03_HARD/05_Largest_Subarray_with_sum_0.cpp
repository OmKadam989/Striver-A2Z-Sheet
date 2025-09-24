// 🔹 Problem: Largest Subarray with 0 Sum (GFG)
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
/*
Given an array arr[], find the length of the longest subarray with sum = 0.

Example:
Input:  arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum = 0 is [-2, 2, -8, 1, 7].
*/

// ------------------------------------------------------
// ✅ Approach 1: Optimal using Prefix Sum + HashMap
// ------------------------------------------------------
/*
Idea:
1. Maintain prefix sum while traversing.
2. If prefix sum becomes 0 → subarray [0...i] has sum = 0.
3. If prefix sum is already in map → we found a subarray with sum = 0.
4. Update maximum length accordingly.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class SolutionOptimal {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int,int> mpp; // stores prefix sum → first index
        int sum = 0, maxi = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum == 0) {
                maxi = i + 1; // subarray from 0...i
            }
            else {
                if (mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]);
                } else {
                    mpp[sum] = i; // store first occurrence
                }
            }
        }
        return maxi;
    }
};


// ------------------------------------------------------
// ✅ Approach 2: Brute Force (Check all subarrays)
// ------------------------------------------------------
/*
Idea:
1. Iterate over all subarrays.
2. Keep sum for each subarray.
3. If sum = 0 → update maximum length.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class SolutionBruteForce {
  public:
    int maxLength(vector<int>& arr) {
        int maxi = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == 0) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};


// ------------------------------------------------------
// 🚀 Driver Code (for testing)
// ------------------------------------------------------
int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    SolutionOptimal opt;
    SolutionBruteForce brute;

    cout << "Optimal Solution Output: " << opt.maxLength(arr) << endl;
    cout << "Brute Force Solution Output: " << brute.maxLength(arr) << endl;

    return 0;
}
