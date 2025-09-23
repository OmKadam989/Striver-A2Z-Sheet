// 🔹 LeetCode 18: 4Sum
// -------------------------------------------------
// Problem: Given an integer array nums and an integer target,
// return all unique quadruplets [a,b,c,d] such that:
// nums[a] + nums[b] + nums[c] + nums[d] == target.
//
// Link: https://leetcode.com/problems/4sum/description/
//
// Approaches included:
// 1. Brute-force (O(n^4))
// 2. Hashset-based (O(n^3 log n))
// 3. Sorting + Two-pointer (O(n^3)) ✅ Optimal
//
// Author: Om Kadam
// GitHub: https://github.com/YourUsername
// -------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// ✅ Approach 1: Brute-force O(n^4)
// Try all quadruplets (TLE for large n)
// -------------------------------------------------
vector<vector<int>> fourSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n-3; i++) {
        for(int j = i+1; j < n-2; j++) {
            for(int k = j+1; k < n-1; k++) {
                for(int x = k+1; x < n; x++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[x];
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[x]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------------------------------------
// ✅ Approach 2: Hashset-based O(n^3 log n)
// Fix 3 elements, search for the 4th in a hashset
// -------------------------------------------------
vector<vector<int>> fourSumHashSet(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            set<long long> hashset;
            for(int k = j+1; k < n; k++) {
                long long fourth = (long long)target - ((long long)nums[i] + nums[j] + nums[k]);
                if(hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------------------------------------
// ✅ Approach 3: Sorting + Two-pointer O(n^3) Optimal
// Similar to 3Sum but with 2 fixed elements
// -------------------------------------------------
vector<vector<int>> fourSumTwoPointer(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates

        for(int j = i+1; j < n; j++) {
            if(j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicates

            int left = j+1, right = n-1;
            while(left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++; right--;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
    }
    return ans;
}

// -------------------------------------------------
// 🚀 Driver Code
// -------------------------------------------------
int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    auto res1 = fourSumBruteForce(nums, target);
    auto res2 = fourSumHashSet(nums, target);
    auto res3 = fourSumTwoPointer(nums, target);

    cout << "Brute-force: ";
    for(auto &quad : res1) {
        cout << "[";
        for(int x : quad) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";

    cout << "Hashset: ";
    for(auto &quad : res2) {
        cout << "[";
        for(int x : quad) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";

    cout << "Two-pointer: ";
    for(auto &quad : res3) {
        cout << "[";
        for(int x : quad) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
