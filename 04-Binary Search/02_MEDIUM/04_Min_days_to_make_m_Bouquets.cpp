// 🔹 Problem: Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
//
// You are given an integer array `bloomDay`, an integer m, and an integer k.
// You need to make `m` bouquets. To make one bouquet, you need to pick `k` adjacent flowers
// that have all bloomed on or before a certain day. 
// Return the minimum number of days needed to make all m bouquets, or -1 if impossible.
//
// Example:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: On day 3, the first, third, and fifth flowers are bloomed → 3 bouquets.
//
// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: Need at least day 12 to have two groups of 3 adjacent flowers.
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// Helper Function: count how many bouquets can be made by `day`
int countBouquets(vector<int> &arr, int day, int k) {
    int bouquets = 0, flowers = 0;
    for (int bloom : arr) {
        if (bloom <= day) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0; // reset after forming one bouquet
            }
        } else {
            flowers = 0; // reset if sequence breaks
        }
    }
    return bouquets;
}

// ---------------- Brute Force ----------------
// Approach:
// Try each possible day from min(bloomDay) to max(bloomDay).
// For each day, count how many bouquets can be made.
// Return the first day where we can make at least m bouquets.
//
// Time Complexity: O(n * range) → can be huge
// Space Complexity: O(1)
int minDaysBrute(vector<int>& bloomDay, int m, int k) {
    long long n = bloomDay.size();
    if (1LL * m * k > n) return -1; // not enough flowers

    int start = *min_element(bloomDay.begin(), bloomDay.end());
    int end = *max_element(bloomDay.begin(), bloomDay.end());

    for (int day = start; day <= end; day++) {
        if (countBouquets(bloomDay, day, k) >= m) {
            return day;
        }
    }
    return -1;
}

// ---------------- Optimal Binary Search ----------------
// Approach:
// Use binary search on the number of days.
// If we can make ≥ m bouquets on day = mid, we can try earlier days (left half).
// Otherwise, we need more days (right half).
//
// Time Complexity: O(n log(range))
// Space Complexity: O(1)
int minDaysOptimal(vector<int>& bloomDay, int m, int k) {
    long long n = bloomDay.size();
    if (1LL * m * k > n) return -1; // impossible

    int lo = *min_element(bloomDay.begin(), bloomDay.end());
    int hi = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (countBouquets(bloomDay, mid, k) >= m) {
            ans = mid;
            hi = mid - 1; // try fewer days
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// ---------------- Driver Code ----------------
int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "Brute Force: " << minDaysBrute(bloomDay, m, k) << endl;
    cout << "Optimal: " << minDaysOptimal(bloomDay, m, k) << endl;

    return 0;
}

/*
Expected Output:
Brute Force: 3
Optimal: 3
*/
