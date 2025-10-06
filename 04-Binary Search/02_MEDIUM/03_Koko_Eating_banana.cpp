// 🔹 Problem: Koko Eating Bananas (LeetCode 875)
// https://leetcode.com/problems/koko-eating-bananas/description/
//
// Koko has n piles of bananas, where piles[i] is the number of bananas in the i-th pile.
// She has h hours to eat all the bananas. She eats at a constant speed k (bananas/hour).
// Each hour, she picks one pile and eats k bananas from it (or the whole pile if fewer).
// If a pile has fewer than k bananas, she finishes it in that hour and doesn't eat more that hour.
//
// Return the minimum integer k such that she can finish all bananas within h hours.
//
// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4
//
// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Try every possible speed k from 1 up to the maximum pile size.
// For each k, compute how many hours it would take to eat all piles.
// The first k for which total hours ≤ h is the answer.
//
// Time Complexity: O(n * m), where m = max(pile size)  
// (because we may test speeds up to m)  
// Space Complexity: O(1)
class SolutionBrute {
public:
    long long hoursNeeded(const vector<int>& piles, int k) {
        long long hours = 0;
        for (int x : piles) {
            // ceiling of x / k
            hours += (x + k - 1) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        for (int k = lo; k <= hi; k++) {
            if (hoursNeeded(piles, k) <= h) {
                return k;
            }
        }
        return hi;
    }
};

// ---------------- Optimal (Binary Search on Answer) ----------------
// Approach:
// Because if Koko can finish with speed k, she can also finish with any speed > k,
// we have a monotonic condition. So we can binary search on k between 1 and max(pile).
//
// Steps:
// 1. lo = 1, hi = max(piles)  
// 2. while lo < hi:
//      mid = (lo + hi) / 2  
//      if hoursNeeded(piles, mid) <= h: hi = mid  
//      else lo = mid + 1  
// 3. lo (or hi) will be the minimum valid k.
//
// Time Complexity: O(n * log M), where M = max(pile)  
// Space Complexity: O(1)
class SolutionOptimal {
public:
    long long hoursNeeded(const vector<int>& piles, int k) {
        long long hours = 0;
        for (int x : piles) {
            hours += (x + k - 1) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

// ---------------- Driver Code ----------------
int main() {
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;

    SolutionBrute brute;
    SolutionOptimal optimal;

    cout << "Brute, Example1: " << brute.minEatingSpeed(piles1, h1) << endl;
    cout << "Optimal, Example1: " << optimal.minEatingSpeed(piles1, h1) << endl;

    cout << "Brute, Example2: " << brute.minEatingSpeed(piles2, h2) << endl;
    cout << "Optimal, Example2: " << optimal.minEatingSpeed(piles2, h2) << endl;

    return 0;
}
