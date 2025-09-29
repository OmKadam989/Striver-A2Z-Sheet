// Missing and Repeating Number Problem
// Problem: Given an array of size n containing numbers from 1 to n, one number is missing and one number is repeating.
// Goal: Find the missing and repeating numbers.
//
// Example:
// Input:  [3, 1, 2, 5, 3]
// Output: Repeating: 3, Missing: 4
//
// Approaches:
// 1. Brute Force: O(n^2), O(1) extra space
// 2. Optimal (Math Formula): O(n), O(1) extra space

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force Solution ----------------
pair<int, int> findBrute(const vector<int>& arr) {
int n = arr.size();
int repeating = -1, missing = -1;

```
for (int x = 1; x <= n; ++x) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
        if (arr[j] == x) cnt++;
    }
    if (cnt == 0) missing = x;
    if (cnt == 2) repeating = x; // assumes repeating number occurs exactly twice
}
return {repeating, missing};
```

}
// ---------------- Better Solution (Index/Negation Method) ----------------
pair<int, int> findBetter(vector<int>& arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;

    // Step 1: Mark visited indices by negating the number at that index
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1; // number x should go to index x-1
        if (arr[index] < 0) {
            // already visited => repeating number
            repeating = abs(arr[i]);
        } else {
            arr[index] = -arr[index];
        }
    }

    // Step 2: Find missing number (the index which is still positive)
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
}


// ---------------- Optimal Solution ----------------
pair<int, int> findOptimal(const vector<int>& arr) {
int n = arr.size();

```
long long S = 1LL * n * (n + 1) / 2;                       // sum of 1..n
long long P = 1LL * n * (n + 1) * (2LL * n + 1) / 6;       // sum of squares of 1..n

long long S1 = 0, P1 = 0;
for (int num : arr) {
    S1 += num;
    P1 += 1LL * num * num;
}

long long diff1 = S1 - S;           // repeating - missing
long long diff2 = P1 - P;           // repeating^2 - missing^2

long long sumRM = diff2 / diff1;    // repeating + missing

long long repeating = (diff1 + sumRM) / 2;
long long missing = repeating - diff1;

return {repeating, missing};
```

}

// ---------------- Driver Code ----------------
int main() {
vector<int> arr = {3, 1, 2, 5, 3};

```
// Brute Force
auto bruteRes = findBrute(arr);
cout << "[Brute Force] Repeating: " << bruteRes.first
     << ", Missing: " << bruteRes.second << endl;

// Optimal
auto optRes = findOptimal(arr);
cout << "[Optimal] Repeating: " << optRes.first
     << ", Missing: " << optRes.second << endl;

return 0;
```

}
