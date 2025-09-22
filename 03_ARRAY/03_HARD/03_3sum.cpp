// 🔹 LeetCode 15: 3Sum
// -------------------------------------------------
// Problem: Given an array nums, find all unique triplets [a,b,c] such that a + b + c = 0
// Link: https://leetcode.com/problems/3sum/description/
// Key Insight: There can be multiple triplets, but all elements in each triplet must sum to zero.
// Approaches included:
// 1. Brute-force counting (O(n^3))
// 2. Hashset-based counting (O(n^2 log n))
// 3. Two-pointer technique (O(n^2) time, O(1) space)
//
// Author: Om Kadam
// GitHub: https://github.com/YourUsername
// -------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// ✅ Approach 1: Brute-force O(n^3)
// Check all triplets and use a set to avoid duplicates
// -------------------------------------------------
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------------------------------------
// ✅ Approach 2: Hashset-based O(n^2 log n)
// Fix one element and use a hashset to find the third
// -------------------------------------------------
vector<vector<int>> threeSumHashSet(vector<int>& nums) {
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        set<int> hashset;
        for(int j = i+1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------------------------------------
// ✅ Approach 3: Two-pointer O(n^2) (Optimal)
// Sort array and use two pointers to find pairs summing to -nums[i]
// -------------------------------------------------
vector<vector<int>> threeSumTwoPointer(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int left = i+1, right = n-1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if(sum < 0) left++;
            else right--;
        }
    }
    return ans;
}

// -------------------------------------------------
// 🚀 Driver Code
// -------------------------------------------------
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};

    auto res1 = threeSumBruteForce(nums);
    auto res2 = threeSumHashSet(nums);
    auto res3 = threeSumTwoPointer(nums);

    cout << "Brute-force: ";
    for(auto &triplet : res1) {
        cout << "[";
        for(int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";

    cout << "Hashset: ";
    for(auto &triplet : res2) {
        cout << "[";
        for(int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";

    cout << "Two-pointer: ";
    for(auto &triplet : res3) {
        cout << "[";
        for(int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
