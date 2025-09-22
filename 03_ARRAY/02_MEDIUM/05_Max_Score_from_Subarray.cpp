// 🔹 Problem: Max Sum in Sub-arrays (GFG)
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

/*  
Approach 1: Brute Force  
- Consider every subarray.  
- For each subarray, find the two smallest elements and calculate their sum.  
- Keep track of the maximum sum encountered.  

Time Complexity: O(n³)  
Space Complexity: O(1)  
*/
class SolutionBrute {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mini = INT_MAX, secMini = INT_MAX;

                // Find two smallest in subarray arr[i...j]
                for (int k = i; k <= j; k++) {
                    if (arr[k] < mini) {
                        secMini = mini;
                        mini = arr[k];
                    } else if (arr[k] < secMini) {
                        secMini = arr[k];
                    }
                }

                if (secMini != INT_MAX) {
                    maxSum = max(maxSum, mini + secMini);
                }
            }
        }
        return maxSum;
    }
};

/*  
Approach 2: Optimal (Observation Based)  
- The maximum sum of the two smallest elements of any subarray  
  always comes from **two adjacent elements**.  
- So, just check all consecutive pairs and take the maximum.  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/
class SolutionOptimal {
public:
    int maxSum(vector<int> &arr) {
        int res = INT_MIN;
        for (int i = 0; i < arr.size() - 1; i++) {
            res = max(res, arr[i] + arr[i + 1]);
        }
        return res;
    }
};
