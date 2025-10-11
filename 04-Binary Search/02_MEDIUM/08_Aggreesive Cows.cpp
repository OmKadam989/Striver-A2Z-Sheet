class Solution {
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
        int count = 1;             // Place first cow at the first stall
        int lastPos = stalls[0];   // Track last placed cow
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            if (count >= cows) return true; // Placed all cows
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        
        int maxDist = stalls[n - 1] - stalls[0];
        int ans = 0;
        
        // 🔹 Try every distance (brute force)
        for (int dist = 1; dist <= maxDist; dist++) {
            if (canWePlace(stalls, dist, k)) {
                ans = dist;  // Store valid distance
            } else {
                break;       // Since further distances will also fail
            }
        }
        return ans;
    }
};
