// 🔹 Problem: Minimize Max Distance to Gas Station
// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
//
// You are given positions of existing gas stations on a number line (`stations[]`).
// You can add **k** new stations anywhere (even at fractional positions).
// After adding them, we define:
//     d = maximum distance between any two adjacent gas stations.
//
// You must minimize `d` and return the smallest possible distance (with 1e-6 precision).
//
// Example:
// Input: stations = [1,2,3,4,5], k = 2
// Output: 0.5
//
// Explanation:
// Add new stations optimally to minimize the largest gap.
//
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------
// Approach:
// 1. Compute the largest gap between existing stations.
// 2. Try possible distances (d) from small to large (e.g., 0.01 step).
// 3. For each d, count how many new stations are needed so that
//    no gap between adjacent stations > d.
// 4. Return the first d for which we can fit within k new stations.
//
// Time Complexity: O(n * (maxGap / step))
// Space Complexity: O(1)
bool canPlace(const vector<double>& stations, int k, double d) {
    long long needed = 0;
    for (int i = 1; i < stations.size(); i++) {
        double gap = stations[i] - stations[i - 1];
        needed += (long long)(gap / d); // how many stations to fill this gap
        if (needed > k) return false;
    }
    return needed <= k;
}

double minimizeMaxDistBrute(vector<double>& stations, int k) {
    double maxGap = 0.0;
    for (int i = 1; i < stations.size(); i++) {
        maxGap = max(maxGap, stations[i] - stations[i - 1]);
    }

    double step = 0.01;
    for (double d = step; d <= maxGap; d += step) {
        if (canPlace(stations, k, d)) {
            return d;
        }
    }
    return maxGap;
}

// ---------------- Optimal (Binary Search on Answer) ----------------
// Key Observation:
// ✅ The smaller the allowed max distance (d), the more new stations are needed.
// ✅ As `d` increases, the number of required new stations decreases — monotonic.
// So we can binary search for the smallest feasible `d`.
//
// Algorithm:
// 1. low = 0, high = maximum gap between adjacent stations.
// 2. While (high - low) > 1e-6:
//       mid = (low + high) / 2
//       If we can place <= k new stations with distance mid → high = mid
//       Else → low = mid
// 3. Return high.
//
// Time Complexity: O(n * log(maxGap / 1e-6))
// Space Complexity: O(1)
double minimizeMaxDistOptimal(vector<double>& stations, int k) {
    int n = stations.size();
    double low = 0.0;
    double high = 0.0;

    for (int i = 1; i < n; i++) {
        high = max(high, stations[i] - stations[i - 1]);
    }

    double eps = 1e-6;
    double ans = high;

    while (high - low > eps) {
        double mid = (low + high) / 2.0;
        if (canPlace(stations, k, mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    return ans;
}

// ---------------- Driver ----------------
int main() {
    vector<double> stations = {1.0, 2.0, 3.0, 4.0, 5.0};
    int k = 2;

    cout << fixed << setprecision(6);
    cout << "[Brute]   -> " << minimizeMaxDistBrute(stations, k) << endl;
    cout << "[Optimal] -> " << minimizeMaxDistOptimal(stations, k) << endl;

    return 0;
}

/*
Expected Output:
[Brute]   -> ~0.500000
[Optimal] -> ~0.500000
*/
