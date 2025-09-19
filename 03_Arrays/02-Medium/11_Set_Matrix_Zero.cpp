// 🔹 Problem: Set Matrix Zeroes (LeetCode 73)
// https://leetcode.com/problems/set-matrix-zeroes/

/*
Given an m x n matrix, if an element is 0, set its entire row and column to 0.  

Example:  
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]  
Output: [[1,0,1],[0,0,0],[1,0,1]]

*/


// ------------------------------------------------------
// ✅ Approach 1: Using Extra Space (Row & Column Arrays)
// ------------------------------------------------------
/*
Steps:
1. Use two arrays row[] and col[] to mark which rows and columns need to be zeroed.
2. Traverse the matrix, and if element == 0 → mark row[i] and col[j].
3. Traverse again and set elements to 0 where row[i] or col[j] is marked.

Time Complexity: O(m * n)  
Space Complexity: O(m + n)
*/
class SolutionExtraSpace {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // Step 1: mark rows and cols
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 2: update matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// ------------------------------------------------------
// ✅ Approach 2: In-Place Marking with Dummy Value
// ------------------------------------------------------
/*
Steps:
1. When matrix[i][j] == 0, mark the entire row and column with a dummy value (e.g., -123456).
   - Don’t overwrite existing zeros during marking.
2. After marking, replace all dummy values with 0.

Time Complexity: O(m * n)  
Space Complexity: O(1) (no extra arrays, but uses a placeholder value)
*/
class SolutionInPlace {
public:
    void rowMatrix(int i, vector<vector<int>> &matrix) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -123456; // dummy value
            }
        }
    }

    void colMatrix(int j, vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -123456; // dummy value
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: mark with dummy values
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowMatrix(i, matrix);
                    colMatrix(j, matrix);
                }
            }
        }

        // Step 2: replace dummy values with 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -123456) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// optimal apprach