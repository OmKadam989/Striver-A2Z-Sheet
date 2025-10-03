// Floor and Ceil in Sorted Array
// Problem: https://takeuforward.org/plus/dsa/problems/floor-and-ceil-in-sorted-array
//
// Given a sorted array and an integer x, find:
// - Floor: greatest element <= x
// - Ceil:  smallest element >= x
//
// Example:
// Input: nums = [3, 4, 4, 7, 8, 10], x = 5
// Output: Floor = 4, Ceil = 7
//
// Approaches:
// 1. Brute Force: O(n)
// 2. Optimal (Binary Search): O(log n)

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// Traverse the array and check for elements <= x and >= x.
// Update floor and ceil accordingly.
vector<int> getFloorAndCeilBrute(vector<int> nums, int x) {
    sort(nums.begin(), nums.end()); // ensure sorted
    int n = nums.size();

    int floor = -1, ceil = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] <= x) floor = nums[i]; // keep updating possible floor
        if (nums[i] >= x) { 
            ceil = nums[i]; 
            break; // first >= x is ceil
        }
    }
    return {floor, ceil};
}

// ---------------- Optimal (Binary Search) ----------------
// Approach:
// Use binary search to track possible floor and ceil candidates.
// If nums[mid] == x → both floor & ceil are nums[mid].
// If nums[mid] < x → nums[mid] is possible floor, move right.
// If nums[mid] > x → nums[mid] is possible ceil, move left.
vector<int> getFloorAndCeilOptimal(vector<int> nums, int x) {
    sort(nums.begin(), nums.end()); // ensure sorted
    int n = nums.size();

    int floor = -1, ceil = -1;
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == x) {
            floor = nums[mid];
            ceil = nums[mid];
            break;
        }
        else if (nums[mid] < x) {
            floor = nums[mid];  // possible floor candidate
            start = mid + 1;
        }
        else {
            ceil = nums[mid];   // possible ceil candidate
            end = mid - 1;
        }
    }
    return {floor, ceil};
}

// ---------------- Driver ----------------
int main() {
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    auto brute = getFloorAndCeilBrute(nums, x);
    auto optimal = getFloorAndCeilOptimal(nums, x);

    cout << "[Brute Force] Floor = " << brute[0] << ", Ceil = " << brute[1] << endl;
    cout << "[Optimal] Floor = " << optimal[0] << ", Ceil = " << optimal[1] << endl;

    return 0;
}

/*
Expected Output:
[Brute Force] Floor = 4, Ceil = 7
[Optimal] Floor = 4, Ceil = 7
*/
