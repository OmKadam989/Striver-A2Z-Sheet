/*
📌 Problem: Longest Sub-Array with Sum K
🔗 Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

---

### Example:
Input:
    arr = [10, 5, 2, 7, 1, -10], k = 15

Output:
    6

Explanation:
    Subarrays with sum = 15 are:
        [5, 2, 7, 1]                → length 4
        [10, 5]                     → length 2
        [10, 5, 2, 7, 1, -10]       → length 6

    Hence, the length of the longest subarray with sum = 15 is **6**.

---

### Brute Force Approach (O(n²)):
1. Start with each index `i` as the beginning of a subarray.
2. Extend the subarray to every index `j >= i`.
3. Keep a running sum while extending.
4. If the sum equals `k`, update the maximum length.

---
### Brute Force Code:
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) {
                    int len = j - i + 1;
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};

/*
### Why TLE?  
- Outer loop runs `n` times.  
- Inner loop also runs up to `n` times.  
- Total complexity = **O(n²)**.  
- If `n = 10⁵`, operations = (10⁵)² = **10¹⁰** → way too large for typical 1–2 second time limits.  
- That’s why this approach gives **Time Limit Exceeded (TLE)**.

---
*/
