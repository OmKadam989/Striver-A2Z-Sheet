/**
 * @file MaximumProductSubarray.cpp
 * @brief Find the maximum product subarray in a given array.
 * 
 * Problem: Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest product.
 * 
 * Approaches:
 * 1. Brute Force O(n^3)
 * 2. Better Brute Force O(n^2)
 * 3. Optimized O(n) (using prefix and suffix product)
 * 
 * Example:
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force O(n^3) ----------------
class BruteForceSolutionN3 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int prod = 1;
                for(int k = i; k <= j; k++) {
                    prod *= nums[k]; // multiply all elements in subarray nums[i..j]
                }
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};

// ---------------- Better Brute Force O(n^2) ----------------
class BruteForceSolutionN2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;

        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = i; j < n; j++) {
                prod *= nums[j]; // multiply while expanding subarray
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};

// ---------------- Optimized O(n) Solution ----------------
class OptimizedSolution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int pre = 1, suffi = 1;

        for(int i = 0; i < n; i++) {
            pre = (pre == 0 ? 1 : pre) * nums[i];
            suffi = (suffi == 0 ? 1 : suffi) * nums[n-i-1];
            maxProd = max(maxProd, max(pre, suffi));
        }

        return maxProd;
    }
};

// ------------------- Driver Code -------------------
int main() {
    vector<int> nums = {2, 3, -2, 4};

    BruteForceSolutionN3 bf3;
    cout << "[Brute Force O(n^3)] Max Product: " << bf3.maxProduct(nums) << endl;

    BruteForceSolutionN2 bf2;
    cout << "[Better Brute Force O(n^2)] Max Product: " << bf2.maxProduct(nums) << endl;

    OptimizedSolution opt;
    cout << "[Optimized O(n)] Max Product: " << opt.maxProduct(nums) << endl;

    return 0;
}
