#include <bits/stdc++.h>
using namespace std;

bool canPlace(const vector<double>& stations, int k, double d) {
    // How many new stations are needed so that no gap > d
    long long needed = 0;
    for (int i = 1; i < stations.size(); i++) {
        double gap = stations[i] - stations[i - 1];
        // Number of new stations to insert so that segments ≤ d
        needed += (long long) (gap / d);
        if (needed > k) return false;
    }
    return needed <= k;
}

double minimizeMaxDist(vector<double>& stations, int k) {
    int n = stations.size();
    double low = 0.0;
    double high = 0.0;
    for (int i = 1; i < n; i++) {
        high = max(high, stations[i] - stations[i - 1]);
    }

    double ans = high;
    double eps = 1e-6;

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

// Brute force for small cases (not for large input)
double minimizeMaxDistBrute(vector<double>& stations, int k) {
    double maxGap = 0.0;
    for (int i = 1; i < stations.size(); i++) {
        maxGap = max(maxGap, stations[i] - stations[i - 1]);
    }
    // Try candidate distances from small steps up to maxGap
    double step = 0.01;
    for (double d = step; d <= maxGap + step; d += step) {
        if (canPlace(stations, k, d)) {
            return d;
        }
    }
    return maxGap;
}

int main() {
    vector<double> stations = {1.0, 2.0, 3.0, 4.0, 5.0};
    int k = 2;

    cout << "[Brute]  Min Max Distance = " << minimizeMaxDistBrute(stations, k) << endl;
    cout << "[Optimal] Min Max Distance = " << minimizeMaxDist(stations, k) << endl;

    return 0;
}
