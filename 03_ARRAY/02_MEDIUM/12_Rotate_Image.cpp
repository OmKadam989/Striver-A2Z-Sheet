// 🔹 Problem: Rotate Image (LeetCode 48)
// https://leetcode.com/problems/rotate-image/

/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise), in place.

Example:
Input:  [[1,2,3],
         [4,5,6],
         [7,8,9]]

Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]
*/


// ------------------------------------------------------
// ✅ Approach 1: Transpose + Reverse (In-Place)
// ------------------------------------------------------
/*
Steps:
1. Transpose the matrix (swap across diagonal).
2. Reverse each row.

Example Walkthrough:
[1 2 3]        [1 4 7]        [7 4 1]
[4 5 6]   →    [2 5 8]   →    [8 5 2]
[7 8 9]        [3 6 9]        [9 6 3]

Time Complexity: O(n^2)  
Space Complexity: O(1) (in-place)
*/
class SolutionInPlace {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: transpose
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


// ------------------------------------------------------
// ✅ Approach 2: Extra Matrix
// ------------------------------------------------------
/*
Steps:
1. Create a new matrix ans[n][n].
2. Place element matrix[i][j] → ans[j][n-i-1].
3. Copy ans back into matrix.

Time Complexity: O(n^2)  
Space Complexity: O(n^2)
*/
class SolutionExtraSpace {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = ans;
    }
};
