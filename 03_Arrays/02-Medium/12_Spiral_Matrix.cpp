// 🔹 Problem: Spiral Matrix (LeetCode 54)
// https://leetcode.com/problems/spiral-matrix/

/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example:
Input:  
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

Output: [1,2,3,6,9,8,7,4,5]
*/


// ------------------------------------------------------
// ✅ Approach: Boundary Traversal
// ------------------------------------------------------
/*
Steps:
1. Maintain four boundaries: top, bottom, left, right.
2. Traverse in spiral order:
   - left → right  (top row)
   - top → bottom  (right column)
   - right → left  (bottom row, if valid)
   - bottom → top  (left column, if valid)
3. After each traversal, shrink the boundary.
4. Continue until all elements are visited.

Time Complexity: O(m * n)  (every element visited once)
Space Complexity: O(1) extra (excluding output vector)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size();

        int left = 0, top = 0;
        int right = n - 1, bottom = m - 1;

        vector<int> ans;

        while (left <= right && top <= bottom) {
            // Traverse left → right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse top → bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse right → left (if still valid)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse bottom → top (if still valid)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
