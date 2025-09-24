int Solution::solve(vector<int> &A, int B) {
    int n1= A.size();
    int cnt = 0;
    for(int i = 0; i < n1; i++) {
        int currXor = 0;
        for(int j = i; j < n1; j++) {
            currXor ^= A[j];  // XOR from i to j
            if(currXor == B) cnt++;
        }
    }
    return cnt;
}
