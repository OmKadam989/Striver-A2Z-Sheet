// 🔹 Problem: Painter’s Partition  
// https://takeuforward.org/arrays/painters-partition-problem/  
// Also see: GFG “Painter’s Partition Problem” :contentReference[oaicite:0]{index=0}
//
// You have `k` painters and `n` boards. Board i has length `boards[i]`.  
// Each painter paints contiguous boards, and painting 1 unit length takes 1 unit time.  
// You want to paint all boards in minimum time.  
// Return the minimum time needed so that all boards are painted by k painters.
//
// Example:
// boards = [5,10,30,20,15], k = 3  
// One optimal assignment:  
//  Painter1 → boards [5,10]  (total = 15)  
//  Painter2 → boards [30]     (total = 30)  
//  Painter3 → boards [20,15]  (total = 35)  
// Time needed = max(15,30,35) = 35  → answer = 35  
//
// Constraints: you may have large sums, so careful with overflow / long types.

#include <bits/stdc++.h>
using namespace std;

// ===================== Brute Force / Recursion + Memoization =====================
// Approach:
// Let f(i, paintersLeft) = minimum time to paint boards from index i to end with given paintersLeft.
// We try giving board ranges [i..j] to the current painter, compute time = sum(i..j), and recursively compute for remaining.  
// We take the maximum of (time for current painter, time for rest) because painters work in parallel, and minimize this maximum over all possibilities.
//
// Time Complexity: O(n^2 * k) (with memoization)  
// Space Complexity: O(n * k)
long long sumPrefix[100005];  // prefix sums for boards

long long rangeSum(int l, int r) {
    return sumPrefix[r] - (l > 0 ? sumPrefix[l-1] : 0);
}

long long solveBrute(int idx, int painters, vector<int>& boards, vector<vector<long long>>& dp) {
    int n = boards.size();
    if (idx == n) {
        return 0;  // no boards left
    }
    if (painters == 0) {
        return LLONG_MAX / 2;  // impossible
    }
    if (dp[idx][painters] != -1) {
        return dp[idx][painters];
    }

    long long ans = LLONG_MAX;
    // assign boards [idx..j] to the current painter, j runs from idx to n-1 – but must leave enough boards for remaining painters
    for (int j = idx; j < n; j++) {
        long long timeCurr = rangeSum(idx, j);
        long long timeRest = solveBrute(j + 1, painters - 1, boards, dp);
        long long worst = max(timeCurr, timeRest);
        ans = min(ans, worst);
        // optimization: if timeCurr already exceeds ans, break
        if (timeCurr > ans) break;
    }
    return dp[idx][painters] = ans;
}

long long painterPartitionBrute(vector<int>& boards, int k) {
    int n = boards.size();
    // build prefix sums
    sumPrefix[0] = boards[0];
    for (int i = 1; i < n; i++) sumPrefix[i] = sumPrefix[i-1] + boards[i];
    vector<vector<long long>> dp(n, vector<long long>(k+1, -1));
    return solveBrute(0, k, boards, dp);
}

// ===================== Optimal: Binary Search + Greedy Feasibility =====================
// Idea:
// If we fix a max time `mid`, we can simulate how many painters are needed if no painter can exceed painting sum > mid.
// We scan boards greedily accumulating sum; when adding next board exceeds `mid`, we assign a new painter.
//
// If neededPainters ≤ k, `mid` is feasible → try lower. Else → increase `mid`.
//
// Answer lies between:
//   low = max(boards)   (at least the largest single board)  
//   high = sum(boards)  (one painter does all)
//
// Time Complexity: O(n * log(sum(boards)))  
// Space Complexity: O(1)
int requiredPainters(const vector<int>& boards, long long maxTime) {
    int painters = 1;
    long long currSum = 0;
    for (int b : boards) {
        if (currSum + b > maxTime) {
            painters++;
            currSum = b;
        } else {
            currSum += b;
        }
    }
    return painters;
}

long long painterPartitionOptimal(vector<int>& boards, int k) {
    long long lo = 0, hi = 0;
    for (int b : boards) {
        lo = max(lo, (long long)b);
        hi += b;
    }
    long long ans = hi;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        int needed = requiredPainters(boards, mid);
        if (needed <= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// ===================== Driver =====================
int main() {
    vector<int> boards = {5, 10, 30, 20, 15};
    int k = 3;

    cout << "Brute Force (DP):   " << painterPartitionBrute(boards, k) << endl;
    cout << "Optimal (Binary):   " << painterPartitionOptimal(boards, k) << endl;

    return 0;
}

/*
Expected Output:
Brute Force (DP):   35
Optimal (Binary):   35
*/
