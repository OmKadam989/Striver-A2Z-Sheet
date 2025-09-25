// 🔹 Problem: Merge Intervals (LeetCode 56)
// https://leetcode.com/problems/merge-intervals/

/*
Given an array of intervals where intervals[i] = [start_i, end_i], 
merge all overlapping intervals and return an array of non-overlapping intervals.

Example:
Input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since [1,3] and [2,6] overlap, merge them into [1,6].
*/

// ------------------------------------------------------
// ✅ Approach 1: Brute Force (Check Ahead)
// ------------------------------------------------------
/*
Steps:
1. Sort intervals by start time.
2. For each interval, extend the "end" by checking further overlapping intervals.
3. Push merged interval into result.

Time Complexity: O(n log n + n^2) ≈ O(n^2) (because of inner loop)
Space Complexity: O(n) (result storage)
*/
class SolutionBruteForce {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end()); // sort by start time
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Skip if already merged
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            // Merge overlapping intervals
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }

            ans.push_back({start, end});
        }
        return ans;
    }
};


// ------------------------------------------------------
// ✅ Approach 2: Optimal (Greedy Merge)
// ------------------------------------------------------
/*
Steps:
1. Sort intervals by start time.
2. Traverse intervals:
   - If current interval overlaps with last in result → merge.
   - Else push it as a new interval.
3. This avoids inner loop.

Time Complexity: O(n log n) (sorting dominates)
Space Complexity: O(n) (result storage)
*/
class SolutionOptimal {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end()); // sort by start time
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // If no overlap, push new interval
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // Else, merge with last interval
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};


// ------------------------------------------------------
// 🚀 Driver Code (for testing)
// ------------------------------------------------------
int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    SolutionBruteForce brute;
    SolutionOptimal opt;

    auto res1 = brute.merge(intervals);
    auto res2 = opt.merge(intervals);

    cout << "Brute Force Output: ";
    for (auto &it : res1) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;

    cout << "Optimal Solution Output: ";
    for (auto &it : res2) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
