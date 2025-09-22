// 🔹 LeetCode 229: Majority Element II
// -------------------------------------------------
// Problem: Find all elements in an array that appear more than n/3 times
// Key Insight: There can be at most 2 such elements (because of n/3 rule)
//
// Approaches included:
// 1. Brute-force counting (O(n^2))
// 2. Hashmap-based counting (O(n) time, O(n) space)
// 3. Boyer-Moore Voting Algorithm (O(n) time, O(1) space)
//
// Author: Om Kadam
// GitHub: https://github.com/YourUsername
// -------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// ✅ Approach 1: Brute-force O(n^2)
// For each element, count its occurrences and check if > n/3
// Pros: Simple
// Cons: Slow for large arrays
// -------------------------------------------------
vector<int> majorityElementBruteForce(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // Skip if already in answer
        if (find(ans.begin(), ans.end(), nums[i]) != ans.end()) continue;

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) cnt++;
        }
        if (cnt > n / 3) ans.push_back(nums[i]);
    }
    return ans;
}

// -------------------------------------------------
// ✅ Approach 2: Hashmap O(n) time & O(n) space
// Use a frequency map to count occurrences
// Add element to answer when its count exceeds n/3
// Pros: Faster than brute-force
// Cons: Uses extra space
// -------------------------------------------------
vector<int> majorityElementHashmap(vector<int>& nums) {
    unordered_map<int, int> freq;
    vector<int> ans;
    int n = nums.size();
    int mini = n / 3 + 1;

    for (int num : nums) {
        freq[num]++;
        if (freq[num] == mini) ans.push_back(num);
        if (ans.size() == 2) break; // max 2 elements possible
    }
    return ans;
}

// -------------------------------------------------
// ✅ Approach 3: Boyer-Moore Voting Algorithm
// Optimized O(n) time & O(1) space
// Key Idea:
// - There can be at most 2 majority elements (> n/3)
// - Maintain two candidates and counts
// - First pass: find potential candidates
// - Second pass: validate counts
// -------------------------------------------------
vector<int> majorityElementBoyerMoore(vector<int>& nums) {
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int elm1 = 0, elm2 = 1; // initial different values

    // First pass: find candidates
    for (int num : nums) {
        if (num == elm1) cnt1++;
        else if (num == elm2) cnt2++;
        else if (cnt1 == 0) { elm1 = num; cnt1 = 1; }
        else if (cnt2 == 0) { elm2 = num; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }

    // Second pass: validate candidates
    cnt1 = cnt2 = 0;
    for (int num : nums) {
        if (num == elm1) cnt1++;
        else if (num == elm2) cnt2++;
    }

    vector<int> ans;
    int mini = n / 3;
    if (cnt1 > mini) ans.push_back(elm1);
    if (cnt2 > mini) ans.push_back(elm2);
    return ans;
}

// -------------------------------------------------
// 🚀 Driver Code
// -------------------------------------------------
int main() {
    vector<int> nums = {3, 2, 3};

    auto res1 = majorityElementBruteForce(nums);
    auto res2 = majorityElementHashmap(nums);
    auto res3 = majorityElementBoyerMoore(nums);

    cout << "Brute-force: ";
    for (int x : res1) cout << x << " ";
    cout << "\n";

    cout << "Hashmap: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";

    cout << "Boyer-Moore: ";
    for (int x : res3) cout << x << " ";
    cout << "\n";

    return 0;
}
