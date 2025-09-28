// Brute force O(n^2), O(1) extra
#include <bits/stdc++.h>
using namespace std;

pair<int,int> findBrute(const vector<int>& arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;
    for (int x = 1; x <= n; ++x) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) if (arr[j] == x) cnt++;
        if (cnt == 0) missing = x;
        if (cnt == 2) repeating = x; // if repeating can appear more than twice adjust
    }
    return {repeating, missing};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 3}; // example
    auto res = findBrute(a);
    cout << "Repeating: " << res.first << " Missing: " << res.second
