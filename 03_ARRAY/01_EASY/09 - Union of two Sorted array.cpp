/*
🔹 Problem: Union of Two Sorted Arrays (GFG)
https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

Given two sorted arrays a[] and b[] of sizes n and m, 
find their union (all distinct elements in sorted order).

Example:
Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both arrays → 1 2 3 4 5 6 7
*/

/* ---------------------------------------------------------------
   ✅ Approach 1: Using Set (Simpler, but less efficient)
   - Insert all elements from both arrays into a set.
   - Since set stores only unique elements in sorted order,
     the union is directly obtained.
   - Convert set back to vector and return.

   Time Complexity: O((N + M) * log(N + M)) due to insertions
   Space Complexity: O(N + M)
-----------------------------------------------------------------*/
class SolutionSet {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> s1;
        for (int i = 0; i < a.size(); i++) {
            s1.insert(a[i]);
        }
        for (int j = 0; j < b.size(); j++) {
            s1.insert(b[j]);
        }

        vector<int> ans(s1.begin(), s1.end());
        return ans;
    }
};

/* ---------------------------------------------------------------
   ✅ Approach 2: Two-Pointer Method (Optimal for Sorted Arrays)
   - Traverse both arrays simultaneously.
   - Compare elements and push smaller one into result.
   - Skip duplicates using unionArr.back().
   - Continue until both arrays are fully traversed.

   Time Complexity: O(N + M) 
   Space Complexity: O(N + M) (for result array)
-----------------------------------------------------------------*/
class SolutionTwoPointer {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1 = a.size(), n2 = b.size();
        vector<int> unionArr;
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (a[i] <= b[j]) {
                if (unionArr.empty() || a[i] != unionArr.back()) {
                    unionArr.push_back(a[i]);
                }
                i++;
            } else {
                if (unionArr.empty() || b[j] != unionArr.back()) {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }

        while (i < n1) {
            if (unionArr.empty() || a[i] != unionArr.back()) {
                unionArr.push_back(a[i]);
            }
            i++;
        }

        while (j < n2) {
            if (unionArr.empty() || b[j] != unionArr.back()) {
                unionArr.push_back(b[j]);
            }
            j++;
        }

        return unionArr;
    }
};
