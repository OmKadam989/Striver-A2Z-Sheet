/*Subarray with Given XOR

Problem: InterviewBit - Subarray with Given XOR

Given an array A of integers and an integer B, find the number of subarrays whose XOR equals B.

Approach 1: Brute Force

Idea:
Check all possible subarrays, compute their XOR, and count the ones that match B.

Steps:

Loop through all starting indices i.

For each starting index, loop through all ending indices j (from i to n-1).

Calculate the XOR of the subarray A[i..j].

If the XOR equals B, increment the count.

Code:
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int currXor = 0;
        for (int j = i; j < n; j++) {
            currXor ^= A[j]; // XOR from i to j
            if (currXor == B) cnt++;
        }
    }

    return cnt;
}

/*
Time Complexity:

Outer loop: O(n)

Inner loop: O(n)

XOR calculation inside inner loop: O(1)

Total: O(n^2)

Space Complexity: O(1)

Approach 2: Using Hash Map (Optimized)

Idea:
Use a hash map to store prefix XOR counts.
If the XOR from start to current index is xr, we want to find a prefix XOR x such that xr ^ x = B ⇒ x = xr ^ B.
The count of such prefixes gives the number of subarrays ending at the current index with XOR B.

Steps:

Initialize xr = 0 and a map mpp to store prefix XOR counts. Add mpp[0] = 1 (for subarrays starting at index 0).

Loop through the array:

Update xr as xr ^= A[i].

Find x = xr ^ B.

Add mpp[x] to the answer (number of subarrays ending here with XOR B).

Increment mpp[xr] by 1.

Return the total count.

Code:
*/
int Solution::solve(vector<int> &A, int B) {
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++; // prefix XOR 0 occurs once
    int cnt = 0;

    for (int i = 0; i < A.size(); i++) {
        xr ^= A[i]; // current prefix XOR
        int x = xr ^ B;
        cnt += mpp[x]; // add count of subarrays ending here with XOR B
        mpp[xr]++;
    }

    return cnt;
}

/*
Time Complexity:

Loop through array: O(n)

Hash map operations: O(1) average (unordered_map)

Total: O(n)

Space Complexity: O(n) (for storing prefix XOR counts)